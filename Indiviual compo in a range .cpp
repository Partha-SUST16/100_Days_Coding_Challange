/**
 Input:
 1



8 5

1 1 1 2 3 5 1 2

1 8

2 3

3 6

4 5

4 8
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
#include <limits.h>
#include <bits/stdc++.h>
#define fw(x) freopen("x.txt","w",stdout)
#define For(i,a,b,c) for(int i = a;i < b;i+=c)
#define REP(i,n) for(int i = 0;i < n;++i)
#define mem(a,s) memset(a,s,sizeof a)
#define fast ios_base::sync_with_stdio(0)
#define pf printf
#define sc scanf
#define ll long long
using namespace std;

const int high = 100003;

struct Query
{
   int L , R , i;
}q[50007];

int ar[high] , ans[50007] , block=0 , answer=0 , mp[high];

bool cmp(Query x , Query y)
{
   if(x.L/block != y.L/block) return x.L/block < y.L/block;

   return x.R < y.R;
}

void add(int pos)
{
   mp[ar[pos]]++;

   if(mp[ar[pos]] == 1) answer++;
}

void rmoving(int pos)
{
   mp[ar[pos]]--;

   if(mp[ar[pos]] == 0) answer--;
}

void Results(int n , int m)
{
   block = (int)sqrt(n);

   sort(q , q+m , cmp);

   int i , currR = 0 , currL = 0 , L , R;

   for(i=0; i<m; i++)
   {
       L = q[i].L;
       R = q[i].R;

       while(currL < L)
       {
           rmoving(currL);
           currL++;
       }

       while(currL > L)
       {
           add(currL-1);
           currL--;
       }

       while(currR <= R)
       {
           add(currR);
           currR++;
       }

       while(currR > R+1)
       {
           rmoving(currR-1);
           currR--;
       }

       int indx = q[i].i;

       ans[indx] = answer;
   }
}

void solution(int m)
{
   for(int i=0; i<m; i++)
   {
       pf("%d\n" , ans[i]);
   }
}

int main()
{
   int t , tc=0 , n , i , qry , x , y;
   sc("%d", &t);
   while(t--)
   {
       memset(mp , 0 , sizeof mp);

       answer = 0;

       sc("%d %d", &n , &qry);

       for(i=0; i<n; i++)
       {
           sc("%d", &ar[i]);
       }

       for(i=0; i<qry; i++)
       {
           //sf("%d %d", &q[i].L , &q[i].R);

           sc("%d", &x);
           sc("%d", &y);
           x--;
           y--;
           q[i].L = x;
           q[i].R = y;
           q[i].i = i;

           q[i].i = i;
       }

       Results(n , qry);

       pf("Case %d:\n" , ++tc);

       solution(qry);
   }

   return 0;
}
