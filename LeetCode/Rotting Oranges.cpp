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

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[]= {0,0,1,-1};/*4 side move*/
        int dy[]= {-1,1,0,0};/*4 side move*/

        int rows = grid.size();
        int colums = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>rottenCordinates;

        for(int i = 0; i < rows ;i++)
        {    for(int j = 0;j<colums;j++)
            {
                if(grid[i][j]==1)//fresh oranges
                    fresh++;
                else if(grid[i][j]==2)//rotten oranges
                    rottenCordinates.push({i,j}) ;// keep their cordinates
            }
        }

        if(fresh==0) return 0;

        int requiredDays = 0;

        while(!rottenCordinates.empty())
        {

            int presentSize = rottenCordinates.size() ; //rottenCordinate size for the begining of the day
            requiredDays++; // extra day

            while(presentSize--)
            {

                auto it = rottenCordinates.front();
                rottenCordinates.pop();

                for(int i = 0; i < 4;i++)// 4 directions
                {
                    int x = it.first+dx[i];
                    int y = it.second+dy[i];

                    if(x >= 0 && x<rows && y>=0 && y<colums && grid[x][y]==1) //check validation
                    {
                        grid[x][y] = 2 ; //mark oranges as rotten
                        rottenCordinates.push({x,y});
                        fresh--;
                    }
                }
            }
            if(fresh==0) // all oranges are rotten now
                break;
        }

        return fresh>0 ? -1 : requiredDays;
    }
};
int main()
{

    return 0;
}
