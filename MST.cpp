#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <cstring>
#include <string>


using namespace std;


struct type
{
    int u,v; ///node
    int w; /// cost
    type(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const type& p) const
    {
        return w < p.w;
    }
};
vector <type>edges;
const int MAX = 1005;
int N, parent[MAX];
int find_parent(int r)
{
    if(parent[r]==r)
        return r;
    return parent[r] = find_parent(parent[r]);
}

void mst()
{
    long long total = 0;
    for(int i = 1;i <=N;i++)
        parent[i] = i;

    sort(edges.begin(),edges.end());
    for(int i =0,u,v;i < edges.size();i++)
    {
        u = find_parent(edges[i].u);
        v = find_parent(edges[i].v);
        if(u!=v)
        {
            parent[v]=u;
            total += edges[i].w;///total cost
        }
    }
    return;
}

int main() {

    return 0;
}
