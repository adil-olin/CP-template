#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#ifdef OL_IN_ONE
#include "debug.h"
#else
#define debug(args...)
#endif

int rnd(int a, int b)
{
    return a + rand() % (b - a + 1);
}

void gen_perm()
{
    int n = rnd(1, 10);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    random_shuffle(p.begin(), p.end());
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

void gen_tree()
{
    int n = rnd(2, 20);
    cout<<n<<endl;
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; ++i)
    {
        edges.emplace_back(rnd(1, i - 1), i);
    }

    vector<int> perm(n + 1); // re-naming vertices
    for (int i = 1; i <= n; ++i)
    {
        perm[i] = i;
    }
    random_shuffle(perm.begin() + 1, perm.end());

    random_shuffle(edges.begin(), edges.end()); // random order of edges

    for (pair<int, int> edge : edges)
    {
        int a = edge.first, b = edge.second;
        if (rand() % 2)
        {
            swap(a, b); // random order of two vertices
        }
        cout<<perm[a]<<" "<<perm[b]<<endl;
    }
}

int main(int argc, char *argv[])
{
    int seed = atoi(argv[1]);
    if (seed == 0)
    {
        freopen("in.txt", "r", stdin);
        string line;
        while (getline(cin, line))
        {
            cout << line << "\n";
        }
        return 0;
    }
    srand(seed);

    return 0;
}