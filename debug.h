void __print(int x) { std::cerr << x; }
void __print(long x) { std::cerr << x; }
void __print(long long x) { std::cerr << x; }
void __print(unsigned x) { std::cerr << x; }
void __print(unsigned long x) { std::cerr << x; }
void __print(unsigned long long x) { std::cerr << x; }
void __print(float x) { std::cerr << x; }
void __print(double x) { std::cerr << x; }
void __print(long double x) { std::cerr << x; }
void __print(char x) { std::cerr << '\'' << x << '\''; }
void __print(const char *x) { std::cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { std::cerr << '\"' << x << '\"'; }
void __print(bool x) { std::cerr << (x ? "true" : "false"); }
void __print(const bitset<64> &b) { std::cerr << b; }
template <typename T, typename V>
void __print(const std::pair<T, V> &x)
{
    std::cerr << '{';
    __print(x.first);
    std::cerr << ", ";
    __print(x.second);
    std::cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    std::cerr << '{';
    for (auto &i : x)
        std::cerr << (f++ ? ", " : ""), __print(i);
    std::cerr << "}";
}
template <typename T, typename V>
void __print(const map<T, V> &x)
{
    int f = 0;
    for (auto &dd : x)
    {
        std ::cerr << (f++ ? ", " : "");
        std ::cerr << "{";
        __print(dd.first);
        std ::cerr << ", ";
        __print(dd.second);
        std ::cerr << "}";
    }
}
template <typename T>
void __print(const stack<T> s)
{
    auto d = s;
    auto dd = s;
    int f = 0;
    while (!dd.empty())
    {
        dd.pop();
    }
    while (!d.empty())
    {
        dd.push(d.top());
        d.pop();
    }
    
    while (!dd.empty())
    {
        cerr << (f++ ? ", " : "");
        __print(dd.top());
        dd.pop();
    }
}
template <typename T>
void __print(const priority_queue<T> p)
{
    auto d = p;
    int f = 0;
    while (!d.empty())
    {
        cerr << (f++ ? ", " : "");
        __print(d.top());
        d.pop();
    }
}

template <typename T>
void __print(const priority_queue<T,vector<T>,greater<T>> p)
{
    auto d = p;
    int f = 0;
    while (!d.empty())
    {
        cerr << (f++ ? ", " : "");
        __print(d.top());
        d.pop();
    }
}

template <typename T>
void __print(const queue<T> p)
{
    auto d = p;
    int f = 0;
    while (!d.empty())
    {
        cerr << (f++ ? ", " : "");
        __print(d.front());
        d.pop();
    }
}

template <typename T>
void __print(const complex<T> p)
{
    std::cerr << '{';
    __print(p.real());
    if(p.imag()<0)
    {
        std::cerr << " - ";
    }
    else
    {
        std::cerr << " + ";

    }
    __print(abs(p.imag()));
    std::cerr << "i }";

}

void _print() { std ::cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        std::cerr << ", ";
    _print(v...);
}
#define debug(x...)                                           \
    cerr << "Line " << __LINE__ << " --- [" << #x << "] = ["; \
    _print(x)