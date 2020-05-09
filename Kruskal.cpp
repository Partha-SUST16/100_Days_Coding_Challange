/**
Input::

**/
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
#include <bits/stdc++.h>
#define fw(x) freopen(x,"w",stdout)
#define For(i,a,b) for(int i = a;i < b;i++)
#define ll long long
#define ull unsinged long long
#define pb push_back
#define sc scanf
#define pf printf
#define mem(m,n) memset(m,n,sizeof m)
#define fast ios_base::sync_with_stdio(0)
#define MAx 1000
using namespace std;

struct edge{
  int u,v,w;
  bool operator <(const edge& p) const
  {
    return w<p.w;
  }
};

int pr[MAX];
vector<edge>e;

int find(inr r)
{
  return (p[r]==r) ? r: find[pr[r]];
}

int mst(int n)
{
  sort(e.begin(),e.end());

  for(int i=1;i<=n;i++)
  pr[i]=i;///parent nije nije

  int count=0,s=0;

  for(int i=0;i<(int)e.size();i++)
  {
    int u=find(e[i].u);
    int v=find(e[i].v);

    if(u!=v)
    {
      pr[u]=v;
      count++;
      s+=e[i].w;

      if(count==n-1) break;
    }
  }
  return s;
}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
      int u,v,w;
      cin>>u>>v>>w;
      edge get;
      get.u=u;
      get.v=v;
      get.w=w;

      e.push_back(get);

    }

    cout<<mst(n)<<endl;
    return 0;
}
