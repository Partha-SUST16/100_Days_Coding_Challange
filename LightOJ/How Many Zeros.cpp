/*
    http://lightoj.com/volume_showproblem.php?problem=1140
*/
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
#define mem(a, s) memset(a, s, sizeof a)
#define fast  ios_base::sync_with_stdio(0);cin.tie(NULL)
#define pf printf
#define sc scanf
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
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
//ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
//ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
//ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}

const int N = 75;
ll dp[2][2][N][N];
ll vis[2][2][N][N];
int lim, cnt;
vector<int> num;

ll DigitDP(int pos, int isSmall, int isStart, int val)
{
    if (pos == lim)
        return val;
    ll &ret = dp[isSmall][isStart][pos][val];
    ll &v = vis[isSmall][isStart][pos][val];

    if (v == cnt)
        return ret;
    v = cnt;
    int end = isSmall ? 9 : num[pos];
    int i;
    ret = 0;
    if (!isStart)
    {
        for (i = 0; i <= end; i++)
            ret += DigitDP(pos + 1, isSmall | (i < num[pos]), 0, (i == 0) + val);
    }
    else
    {
        for (i = 1; i <= end; i++)
        {
            ret += DigitDP(pos + 1, isSmall | (i < num[pos]), 0, (i == 0) + val);
        }
        ret += DigitDP(pos + 1, 1, 1, 0);
    }
    return ret;
}

ll cal(ll x)
{
    if (x < 0)
        return 0;
    if (x <= 9)
        return 1;
    num.clear();
    while (x)
    {
        num.pb(x % 10);
        x /= 10;
    }
    reverse(all(num));
    lim = num.size();
    cnt++;
    return DigitDP(0, 0, 1, 0) + 1;
}
int main()
{
    int t = 1, tt;
    sc("%d", &tt);
    while (tt--)
    {
        ll b, e;
        sc("%lld%lld", &b, &e);
        pf("Case %d: %lld\n", t++, (cal(e) - cal(b - 1)));
    }
    return 0;
}