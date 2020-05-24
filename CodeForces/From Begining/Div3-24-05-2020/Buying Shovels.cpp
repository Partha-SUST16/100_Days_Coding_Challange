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

struct primeFactorization
{


    int countOfPf, primeFactor;
};

vll ans;
ll n,k;

void generateDivisors(int curIndex, int curDivisor,
                      vector<primeFactorization>& arr)
{

    if (curIndex == arr.size())
    {
        ans.pb(curDivisor);
        return;
    }

    for (int i = 0; i <= arr[curIndex].countOfPf; ++i)
    {
        generateDivisors(curIndex + 1, curDivisor, arr);
        curDivisor *= arr[curIndex].primeFactor;
    }
}

void findDivisors(int n)
{


    vector<primeFactorization> arr;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int count = 0;
            if(i<=k)
            {

                while (n % i == 0)
                {
                    n /= i;
                    count += 1;
                }
            }

            arr.push_back({ count, i });
        }
    }

    if (n > 1)
    {
        arr.push_back({ 1, n });
    }

    int curIndex = 0, curDivisor = 1;

    generateDivisors(curIndex, curDivisor, arr);
}
void process()
{
    findDivisors(n);
    sort(all(ans));
    for(int i = ans.size()-1; i>=0; i--)
    {
        if(ans[i]<=k)
        {
            cout<<n/ans[i]<<endl;
            break;
        }
    }
}
int main()
{
    fast;
    int t;
    cin >> t;
    while(t--)
    {

        cin >> n >> k;
        ans.clear();
        process();

    }
    return 0;
}
