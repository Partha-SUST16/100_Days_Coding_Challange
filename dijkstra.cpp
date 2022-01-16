#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u,w;
    node() {}
    node(int u, int w): u(u),w(w) {}
    bool operator < (const node &p) const
    {
        return w<p.w;
    }
};

vector<vector<pair<int,int>>> adj;
vector<int> cost;
void dijsktra(int source, int destination)
{
    //vector<int> cost(100005 + 1, 1e9);
    priority_queue<node> que;
    que.push(node(source, 0));
    cost[source] = 0;
    while(!que.empty())
    {
        int u = que.top().u, w = que.top().w;
        que.pop();
        //if(u==destination) return w;

        for(int i = 0 ; i <adj[u].size(); i++)
        {
            int v = adj[u][i].first, ww = adj[u][i].second;
            if(w+ww<cost[v])
            {
                cost[v] = w+ww;
                que.push(node(v,cost[v]));
            }
        }
    }
}
int main()
{

    int q,n,e;
    cin >> n >> e >> q;
    adj.clear();
    adj.resize(n + 1);
    cost.resize(n + 1, 1e9);
    while (e--)
    {
        int x, y, z; //pair of nodes, cost
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
    }
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        cost.resize(n + 1, 1e9);
        dijsktra(src, des);
        for(auto i : cost) {
            cout<<i<<endl;
        }
    }
    return 0;
}
