/*input
3
4
ACGT
ACGTGCGT
ACCGTGC
ACGCCGT
3
CGCGCGCGCGCGCCCCGCCCGCGC
CGCGCGCGCGCGCCCCGCCCGCAC
CGCGCGCGCGCGCCCCGCCCGCTC
2
CGCGCCGCGCGCGCGCGCGC
GGCGCCGCGCGCGCGCGCTC
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

const int N = 2500005;
int sz = 0;
int nexti[N][4];
int endi[N],len[N];
ll ans = 0;
int fuck(char c)
{
	if(c=='G')return 1;
	if(c=='T')return 3;
	return c-'A';
}

void insert(string &s)
{
	int v = 0;
	int length = 0;
	for(int i=0;i<s.length();i++)
	{
		int c = fuck(s[i]);
		if(nexti[v][c]==-1)
		{
			nexti[v][c] = ++sz;
		}
		v = nexti[v][c];
		len[v] = ++ length;
		endi[v]++;
	}
}

bool search(string s)
{
	int v = 0;
	for(int i=0;i<s.size();i++)
	{
		int c = fuck(s[i]);
		if(nexti[v][c]==-1)
			return 0;
		v = nexti[v][c];
	}
	return endi[v]>0;
}
void traverse()
{
	ans = 0;
	for(int i=1;i<=sz;i++)
	{
		ans = max(ans,1LL*endi[i]*len[i]);
	}
}
void reset()
{
	mem(nexti,-1);
	mem(endi,0);
}
int main()
{
    int t=1,tt;
    sc("%d",&tt);
    while(tt--)
    {
    	int n;
    	sc("%d",&n);
    	string s;
    	sz = 0;
    	reset();

    	for(int i=0;i<n;i++)
    	{
    		cin >> s;
    		insert(s);
    	}
    	traverse();
    	pf("Case %d: %lld\n",t++,ans);
    }
    return 0;
}