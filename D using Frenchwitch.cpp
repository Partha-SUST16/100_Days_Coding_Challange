#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <bits/stdc++.h>
#define fw(x) freopen("x.txt", "w", stdout)
#define For(i, a, b, c) for (int i = a; i < b; i += c)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REP1(i, n) for (int i = 1; i <= n; i++)
#define mem(a, s) memset(a, s, sizeof a)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL)
#define pf printf
#define sc scanf
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define vii vector<int>
#define vll vector<ll>
#define vss vector<string>
#define debug(x) cout << #x "=" << (x) << endl
#define pb push_back
#define sz(x)        int((x).size())


using namespace std;

// moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//big_mod

//ll bigmod(ll a,ll b,ll m)
//{if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a)% m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
//ll setBit1(ll num, int idx) {return num or (1ll<<idx);}
//ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
//ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}

const int N = (int)2e5 + 5;
const int mod = 1000000007;
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
struct Fenwick {
    using T = int;
    //static const T ID = 0;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) : s(n, 0) {}

    // A[i] = f(A[i], v); time: O(lg n)
    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    // Get f(A[0], .., A[i-1]); time: O(lg n)
    T query(int i) {
        T v = 0;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }

    // Find smallest i such that
    // f(A[0],...,A[i-1]) >= val; time: O(lg n)
    // Prefixes must have non-descreasing values.
    int lowerBound(T val) {
        if (val <= 0) return 0;
        int i = -1, mask = 1;
        while (mask <= sz(s)) mask *= 2;
        T off = 0;
        while (mask /= 2) {
            int k = mask+i;
            if (k < sz(s)) {
                T x = f(off, s[k]);
                if (val > x) i=k, off=x;
            }
        }
        return i+2;
    }
};
int main()
{
    int n,q;
    Fenwick tree(n);
    cin >> n >> q;
    for(int i=0,x;i<n;i++)
        cin >> x,x--,tree.modify(x,1);
    for(int i=0,k;i<q;i++)
    {

        cin >> k;
        if (k >= 1) {
            k--;
            tree.modify(k, 1);
        } else {
            k = -k;
            int j = tree.lowerBound(k);
            tree.modify(j-1, -1);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(tree.query(i+1)-tree.query(i))
            return cout<<i+1<<endl,0;
    }
    cout<<0<<endl;
    return 0;
}
