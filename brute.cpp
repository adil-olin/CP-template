#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

#ifdef OL_IN_ONE
#include "debug.h"
#else
#define debug(args...)
#endif


int main()
{
    #if OL_IN_ONE
    auto start = high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int>got;
    got={5,6,1,2,3};
    long long int ans = 0,k=7;
    for(int i=1,sgn=-1;k;k--)
    {
        if(i+sgn==5)
        {
            sgn = -1;
        }
        if(i+sgn<0)
        {
            sgn = 1;
        }
        i+=sgn;
        ans+=got[i];
        debug(got[i],i);
        got[i]=0;
        //debug(got,i,sgn);
        for(int j=0;j<5;j++)
        {
            got[j]++;
        }
    }
    cout<<ans<<endl;

    #if OL_IN_ONE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    #endif
    return 0;
}