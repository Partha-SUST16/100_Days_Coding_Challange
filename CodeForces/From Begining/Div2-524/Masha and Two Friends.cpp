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

const int N = (int)2e5 + 5;
const int mod = 1000000007;
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

pll get(ll a,ll b,ll c,ll d)
{
    ll cell = (c-a+1)*(d-b+1);
    if(cell%2==0) return make_pair(cell/2,cell/2);
    else
    {
        if(((a+b)%2) == 0)return make_pair(cell/2 +1,cell/2);
        else
            return make_pair(cell/2,cell/2 +1);
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n,m,x1,x2,x3,x4,y1,y2,y3,y4;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        ll totCell = (n*m);
        ll white = (totCell+1)/2;
        ll black = (totCell)/2;

        ll lx = max(x1,x3),rx = min(x2,x4),dy=max(y1,y3),uy =  min(y2,y4);
        pll p1 = get(x1,y1,x2,y2),p2=get(x3,y3,x4,y4);
        pll p3 = make_pair(0,0);
        if(lx<=rx and dy<=uy)
            p3 = get(lx,dy,rx,uy);

        ll pureBlack = p1.second-p3.second;

        white+=pureBlack;
        black-=pureBlack;
        black+=p2.first;
        white-=p2.first;
        cout<<white<<' '<<black<<endl;
    }
    return 0;
}
