/*input
zxcvbn
hjgasbznxbzmx
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
 #define fw(x) freopen("x.txt","w",stdout)
 #define For(i,a,b,c) for(int i = a;i < b;i+=c)
 #define REP(i,n) for(int i = 0;i < n;++i)
 #define mem(a,s) memset(a,s,sizeof a)
 #define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
 #define pf printf
 #define sc scanf
 #define ll long long
 #define pii pair<int,int>
 #define pll pair<ll,ll>
 #define all(v) v.begin(),v.end()
 #define debug(x)  cout<<#x"="<<(x)<<endl
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
const int N = 100;
int dp[N][N];
int n,m;
string a,b;

int LCS(int i,int j)
{
	if(i==n or j==m)return 0;
	if(dp[i][j]!=-1)return dp[i][j];

	int ans= 0;
	if(a[i]==b[j])
		ans = 1+ LCS(i+1,j+1);
	else 
	{
		int val1 = LCS(i+1,j);
		int val2 = LCS(i,j+1);
		ans = max(val2,val1);
	}
	return dp[i][j]=ans;
}
string ans;
void printLCS(int i,int j)
{
	if(i==n or j==m)
	{
		cout<<ans<<endl; return;
	}
	if(a[i]==b[j])
	{
		ans+=a[i];
		printLCS(i+1,j+1);
	}
	else 
	{
		if(dp[i+1][j]>dp[i][j+1])
			printLCS(i+1,j);
		else 
			printLCS(i,j+1);
	}
}
void printALL(int i,int j)
{
	if(i==n or j==m)
	{
		cout<<ans<<endl;return;
	}
	if(a[i]==a[j])
	{
		ans+=a[i];
		printALL(i+1,j+1);
		ans.erase(ans.end()-1);

	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1])
			printALL(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1])
			printALL(i,j+1);
		else 
		{
			printALL(i+1,j); printALL(i,j+1);
		}
	}
}
int main()
{
	cin>>a>>b;
	n = a.length();
	m = b.length();
	mem(dp,-1);  
	cout<<LCS(0,0)<<endl;
	ans="";  
	printLCS(0,0);
	ans="";
	printALL(0,0);
    return 0;
}