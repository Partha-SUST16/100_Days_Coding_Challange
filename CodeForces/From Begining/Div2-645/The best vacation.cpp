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

const int N = (int)400005;
const int mod = 1000000007;
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}
ll n,x,mx;
ll arr[N],pre[N],pre2[N];
ll rangeSum(ll l, ll r)
{
    return r*(r+1)/2-l*(l+1)/2;
}
int main()
{
    cin >> n >> x;
    REP1(i,n)
    {
        cin >> arr[i];
        mx = max(mx,arr[i]);
        pre[i] = pre[i-1]+arr[i];
        pre2[i] = pre2[i-1]+arr[i]*(arr[i]+1)/2;
    }
    for(int i = n+1; i < 2*n; i++)
    {
        pre[i]=pre[i-1]+arr[i-n];
        pre2[i]=pre2[i-1]+arr[i-n]*(arr[i-n]+1)/2;
    }
    if(x <= mx)
    {
        ll ans=0;
        while(x--)
        {
            ans+=mx--;
        }
        cout<<ans<<endl;
        return 0;
    }
    ll ans=0;
    for(int i = 0; i < n; i++)
    {
        auto it = lower_bound(pre+i,pre+2*n,pre[i]+x);
        ll wh = *it-pre[i]-x;

        ll temp=pre2[it-pre]-pre2[i]-wh*(wh+1)/2+rangeSum(wh,*it-pre[i]-x);
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}
