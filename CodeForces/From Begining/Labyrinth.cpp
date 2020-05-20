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

int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
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

const int N = 2200;
const int mod = 1000000007;
//ll qpow(ll n,ll k) {ll ans=1;assert(k>=0);n%=mod;while(k>0){if(k&1) ans=(ans*n)%mod;n=(n*n)%mod;k>>=1;}return ans%mod;}

void bfs(int a,int b,vector<vector<pii>> &d)
{
    deque<pii>q;
    q.pb({a,b});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for(int i=0; i<4; i++)
        {
            int nx= x+dx[i];
            int ny = y+dy[i];
            if(d[nx][ny] != make_pair(mod,mod))continue;
            if(i==0)
            {
                d[nx][ny] = {d[x][y].first+1,d[x][y].second};
                q.pb({nx,ny});
            }
            else if(i==1)
            {
                d[nx][ny] = {d[x][y].first,d[x][y].second+1};
                q.pb({nx,ny});
            }
            else
            {
                d[nx][ny] = { d[x][y].first,d[x][y].second };
                q.push_front({nx,ny});
            }
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pii>>d(n+2,vector<pii>(m+2, {-1,-1}));
    REP1(i,n)
    REP1(j,m) d[i][j] = {mod,mod};
    int a,b;
    cin >> a >> b;
    int l,r;
    cin >> l >> r;
    REP1(i,n)
    {
        REP1(j,m)
        {
            char c;
            cin >> c;
            if(c=='.')d[i][j]= {mod,mod};
            else
                d[i][j] = {-1,-1};
        }
    }
    d[a][b] = {0,0};
    bfs(a,b,d);
    int ans = d[0][0].first+1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (d[i][j] == make_pair(-1,-1))
            {
                continue;
            }
            if (d[i][j].first <= l && d[i][j].second <= r)
            {
                ans++;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
