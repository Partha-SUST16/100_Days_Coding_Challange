/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#include<bits/stdc++.h>
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y)
{
    if(y < x) x = y;
}
template<typename T, typename U> inline void amax(T &x, U y)
{
    if(x < y) x = y;
}
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x/= 10;
    }
    while(x);
    do
    {
        putchar(buf[i]);
    }
    while (buf[i++] != '\n');
}


/************************************/


/******* Debugging Class Template *******/
#define DEBUG

#ifdef DEBUG

#define debug(args...)     (Debugger()) , args

class Debugger
{
public:
    Debugger(const std::string& _separator = " - ") :
        first(true), separator(_separator) {}

    template<typename ObjectType> Debugger& operator, (const ObjectType& v)
    {
        if(!first)
std:
            cerr << separator;
        std::cerr << v;
        first = false;
        return *this;
    }
    ~Debugger()
    {
std:
        cerr << endl;
    }

private:
    bool first;
    std::string separator;
};

#else
#define debug(args...)                  // Just strip off all debug tokens
#endif

/**************************************/

/******** User-defined Function *******/


/**************************************/


/********** Main()  function **********/
const char DUMMY = '.';
long long lcm(long long a,long long b)
{
    return (a*b)/__gcd(a, b);
}
int n,prime[200005];

void sieve()
{
    for(int i=2; i<=200000; i++) prime[i] = i;
    for(int i=4; i<=200000; i+=2) prime[i] = 2;
    for(int i=3; i*i<=200000; i+=2)
    {
        if(prime[i] == i)
        {
            for(int j=i*i; j<=200000; j+=i)
            {
                if(prime[j] == j) prime[j] = i;
            }
        }
    }
}
string manacher(string s)
{
    string s1;
    s1.clear();
    int n = s.size() * 2 - 1;
    int kk=s.size()-1;
    vector <int> f = vector <int>(n, 0);
    string a = string(n, DUMMY);
    for (int i = 0; i < n; i += 2) a[i] = s[i / 2];
    int kk1=a.size()-1;
    int l = 0, r = -1, center, res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        j = (i > r ? 0 : min(f[l + r - i], r - i)) + 1;
        while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) j++;
        f[i] = --j;
        if (i + j > r)
        {
            r = i + j;
            l = i - j;
        }

        int len = (f[i] + i % 2) / 2 * 2 + 1 - i % 2;
        if ((len > res))
        {
            if ((center/2-(len/2)<=0) or
                    (center/2+(len/2)>=kk))
            {
                res = len;
                center = i;
            }
        }
    }
    s1.clear();
    int i = center;
    int j = center;
    while(i>=0 && j<=kk1)
    {
        if (a[i]!=a[j]) break;
        if (i==j && a[i]!='.') s1+=a[i];
        else
        {
            if (a[i]!='.') s1 = a[i] + s1 + a[j];
        }
        i--;
        j++;
        if (i<0 or j>kk1) break;
    }
    return s1;
}
unordered_map<int,int> getFactors(int x)
{
    unordered_map<int,int> m;
    int cnt = 1;
    while(x != 1)
    {
        if(prime[x] == prime[x/prime[x]]) cnt++;
        else m[prime[x]] = cnt, cnt = 1;
        x /= prime[x];
    }
    return m;
}
#define ll long long
int k, p[200005],  a[100005];

void snt(int n)
{
    for (int i = 2; i <= n; i++) p[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (p[i] == i)
        {
            for (int j = i; j <= n; j += i) p[j] = i;
        }
    }
}

int d[200005][22];
void run();
int main()
{

#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

    run();
    return 0;
}
/********  Main() Ends Here *************/
void run()
{
    int n, k;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
    vector<int> ara(n);
    set<int> e;
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
        if (ara[i] == k)
        {
            e.insert(i);
        }
        ara[i] = ara[i] >= k ? 1 : -1;
        if (i) ara[i] += ara[i - 1];
    }
    vector<int> mx = ara;
    for (int i = n - 2; i >= 0; i--)
    {
        mx[i] = max(mx[i], mx[i + 1]);
    }
    bool flag = false;
    for (int i = 0; i + 1 < n; i++)
    {
        auto it = e.lower_bound(i);
        if (it == e.end()) break;
        int ttt = max(*it, i + 1);
        int pre = i > 0 ? ara[i - 1] : 0;
        if (mx[ttt] - pre > 0)
        {
            flag = true;
            break;
        }
    }
    flag |= e.size() == n;
    cout << (flag ? "yes\n" : "no\n");
    }
    return ;
}
