/*input
5
1 2 3 0 3
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
#define fast ios_base::sync_with_stdio(0)
#define pf printf
#define sc scanf
#define ll long long
#define debug(x) cout << #x "=" << (x) << endl
#define all(v) v.begin(), v.end()
using namespace std;

// moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//big_mod

//ll bigmod(ll a,ll b,ll m)
//{if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a)% m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

int main()
{
	int n;
	cin >> n;
	int a[n + 5];
	ll sum = 0, ans = 0;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 3 != 0 or n < 3)
		return cout << 0 << endl, 0;
	ll ave = sum / 3;
	ll temp = 0;
	for (int i = 0; i < n - 2; i++)
	{
		temp += a[i];
		if (temp == ave)
			v.push_back(i);
	}
	temp = 0;

	for (int i = n - 1; i > 1; i--)
	{
		temp += a[i];
		if (temp == ave)
		{
			ans += lower_bound(all(v), i - 1) - v.begin();
		}
	}
	cout << ans << endl;

	return 0;
}