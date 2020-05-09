
 /**
  * In this code we have a very large array called arr, and very large set of operations
  * Operation #1: Increment the elements within range [i, j] with value val
  * Operation #2: Get max element within range [i, j]
  * Build tree: build_tree(1, 0, N-1)
  * Update tree: update_tree(1, 0, N-1, i, j, value)
  * Query tree: query_tree(1, 0, N-1, i, j)
  * Actual space required by the tree = 2*2^ceil(log_2(n)) - 1
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
#define fast ios_base::sync_with_stdio(0)
#define pf printf
#define sc scanf
#define ll long long
#define MAX 1000000
#define N 3000
using namespace std;


int64_t arr[100006];
int64_t t[262200];
int64_t lazy[262200];

void build(int64_t node, int64_t a, int64_t b)
{
	if(a>b) return;
	if (a==b)
	{
		t[node]=arr[a];
		return;
	}

	build(node*2, a, (a+b)/2);
	build(node*2+1,(a+b)/2+1,b);

	t[node]=t[node*2]+t[node*2+1];
}

int64_t query(int64_t node, int64_t a, int64_t b, int64_t i, int64_t j)
{
	if(a>b||a>j||b<i) return 0;
	if (lazy[node] !=0 )
	{
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}

	if (a>=i && b<=j) return t[node];

	int64_t q1=query(node*2, a, (a+b)/2, i, j);
	int64_t q2=query(node*2+1, (a+b)/2+1, b, i, j);

	return q1+q2;
}

void update(int64_t node, int64_t a, int64_t b, int64_t i, int64_t j, int64_t inc)
{
	if(a>b) return;
	if (lazy[node]!=0)
	{
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>b||a>j||b<i) return;

	if (a>=i && b<=j)
	{
		t[node]+=inc*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=inc;
			lazy[node*2+1]+=inc;
		}
		return;
	}

	update(node*2, a, (a+b)/2, i, j, inc);
	update(node*2+1, (a+b)/2+1, b,i, j, inc);
	t[node] = t[node*2] + t[node*2+1];
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	int64_t t,n,qu,q,p,a; cin>>t;
	int64_t inc;
	while(t--)
	{
		cin>>n>>qu;
		build(1,0,n-1);
		for (int i = 0; i < 262200; ++i) lazy[i]=0;
		while(qu--)
		{
			cin>>a;
			if (a==0)
			{
				cin>>p>>q>>inc;
				update(1,0,n-1,p-1,q-1,inc);
			}
			else
			{
				cin>>p>>q;
				cout<<query(1,0,n-1,p-1,q-1)<<endl;
			}
		}

	}
	return 0;
}
