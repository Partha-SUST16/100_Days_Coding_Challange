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
/**
    1st: 0,1,2
    2nd: depends on 1st position { 0,1 on first position can have 0-9}, {2 on first position can have 0-3}
    3rd: {0-5}
    4th: {0-9}

    So only 2nd position is depending on the 1st position and dependency is only with number 2.

    The approach will be to try out 1st position with number 2(if given in the input) if this works out, good.
    Else will place 1 (0 if 1 not available.) and try again.
    [2,0,6,6] case : valid time exists: "06:26"
**/
class Solution
{
    void dfs(vector<int>& A, int pos, unordered_map<int,int>& freq, string& largest, string& temp)
    {
        if (pos == 4)
        {
            if (temp > largest)
                largest = temp;
            return;
        }
        for (int i=0; i <= 9; i++)
        {
            if (freq[i] > 0)
            {
			   // check what is suitable at each position
                if (pos == 0)
                {
                    if (i >=0 && i <= 2)
                    {
                        freq[i]--;
                        temp.push_back(i+'0');
                        dfs(A, pos + 1, freq, largest, temp);
                        temp.pop_back();
                        freq[i]++;
                    }
                }
                else
                if (pos == 1)
                {
                    if (temp[0] - '0' <= 1 || ((temp[0] == '2') && i>=0 && i<=3))
                    {
                            freq[i]--;
                            temp.push_back(i+'0');
                            dfs(A, pos + 1, freq, largest, temp);
                            temp.pop_back();
                            freq[i]++;
                    }
                }
                else
                if (pos == 2)
                {
                    if (i >= 0 &&  i<=5)
                    {
                        freq[i]--;
                        temp.push_back(i+'0');
                        dfs(A, pos + 1, freq, largest, temp);
                        temp.pop_back();
                        freq[i]++;
                    }
                }
                else
                {
                        freq[i]--;
                        temp.push_back(i+'0');
                        dfs(A, pos + 1, freq, largest, temp);
                        temp.pop_back();
                        freq[i]++;
                }
            }

        }
    }
public:
    string largestTimeFromDigits(vector<int>& A) {

        string largest;
        unordered_map<int, int> freq;
        for(int i = 0; i < 4;i++)
            freq[A[i]]++;
        string temp;
        dfs(A, 0, freq, largest, temp);

		// if we returned earlier then 'largest'was not fully formed.
        if (largest.size() < 4)
            return "";

        largest.push_back(largest[3]);
        largest[3] = largest[2];
        largest[2]=':';
        return largest;
    }
};
int main()
{

    return 0;
}
