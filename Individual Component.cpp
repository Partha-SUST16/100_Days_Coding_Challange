#include<bits/stdc++.h>
#define LL long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18

using namespace std;

unordered_map<int,int> pos;
int ar[300005];
int tree[16*300000+5];
int lft[16*300000+5];
int rht[16*300000+5];
int root[600005];
int rt[300005];
int idx;

inline void build(int node,int start,int end)
{
    if(start==end)
        {
            tree[node]=0;
            return;
        }
        lft[node]=idx++;
        rht[node]=idx++;
        int mid=(start+end)/2;
        build(lft[node],start,mid);
        build(rht[node],mid+1,end);
        tree[node]=0;
}

inline int update(int node,int start,int end,int pos,int val)
{
    int x;
    x=idx++;
    if(start==end)
    {
        tree[x]=val;
        return x;
    }
    lft[x]=lft[node];
    rht[x]=rht[node];
    int mid=(start+end)/2;
    if(pos<=mid)
        lft[x]=update(lft[x],start,mid,pos,val);
    else
        rht[x]=update(rht[x],mid+1,end,pos,val);

    tree[x]=tree[lft[x]]+tree[rht[x]];

    return x;
}

inline int query(int node,int start,int end,int l,int r)
{
    if(start>r || end<l)
        return 0;
    else if(start>=l && end<=r)
        return tree[node];
    int mid=(start+end)/2;
    int q1=query(lft[node],start,mid,l,r);
    int q2=query(rht[node],mid+1,end,l,r);

    return (q1+q2);
}


int main()
{
    std:ios_base::sync_with_stdio(false);
    int n;
    s(n);

    int i;

      idx=0;
       root[0]=0;
        build(0,1,n);

    int t=1;
    for(i=1;i<=n;i++)
    {
        s(ar[i]);
        int k=pos[ar[i]];
        if(k!=0)
        {
            root[t]=update(root[t-1],1,n,k,0);
            t++;
            root[t]=update(root[t-1],1,n,i,1);
            t++;
        }
        else
        {
            root[t]=update(root[t-1],1,n,i,1);
            t++;
        }

        rt[i]=t-1;
        pos[ar[i]]=i;
    }

    int m;
    s(m);

    while(m--)
    {
        int a,b;
        s(a);
        s(b);

        p(query(root[rt[b]],1,n,a,b));
        ent;
    }

 return 0;

}
