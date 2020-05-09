#include<cstdio>
#include<vector>
#include<algorithm>



using namespace std;

struct type
{
    int u, v;
    int w;
    type(int u, int v, int w):u(u),v(v),w(w){}
    type(int u_, int v_, int w_){
        u=u_;
        v=v_;
        w=w_;
    }
    bool operator < (const type& p) const
    {
        return w < p.w;
    }
};

vector<type>edges;
//edges e = edges(4,5,6);

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
    for(int i=1; i<=N; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end());
    for(int i=0, u, v; i<edges.size(); i++)
    {
        u = find_parent(edges[i].u);
        v = find_parent(edges[i].v);
        if(u!=v)
        {
            parent[u] = v; // optimization possible here!!!
            total += edges[i].w;
        }
    }
    return ;
}

int main()
{
    return 0;
}




