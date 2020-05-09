#include <bits/stdc++.h>
#define fw(x) freopen("x.txt","w",stdout)
#define For(i,a,b,c) for(int i = a;i < b;i+=c)
#define REP(i,n) for(int i = 0;i < n;++i)
#define mem(a,s) memset(a,s,sizeof a)
#define fast ios_base::sync_with_stdio(0)
#define pf printf
#define sc scanf
#define ll long long
#define N 1000000+10
using namespace std;

 std::vector<ll>prime;
 bool mark[N];
 void seive()
 {
   int sq=sqrt(N);
   mem(mark,true);

   mark[0]=mark[1]=false;
   for(int i=4;i<=N;i+=2) mark[i]=false;

   for(int i=3;i<=sq;i+=2)
   {
     if(mark[i])
     {
       for(int j=i*i;j<=sq;j+=2*i)
        mark[j]=false;
     }
   }
   prime.push_back(2);

   for(int i=3;i<=N;i+=2)
    if(mark[i])
      prime.push_back(i);
 }
int main()
{

  return 0;
}
