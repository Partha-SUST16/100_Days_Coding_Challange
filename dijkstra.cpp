#include <bits/stdc++.h>

using namespace std;

struct node{
    int u, w;
    node(){}
    node(int u, int w):u(u),w(w){}
    bool operator < (const node& p) const{
        return w > p.w;
    }
};

const int MAX = 105;
vector<pair<int,int> > v[MAX];
int dist[MAX], N;

void dijkstra(){
    int s=1, d=N;
    priority_queue<node> Q;
    memset(dist, 63, sizeof dist);
    dist[s] = 0;
    Q.push(node(s,0));
    while(!Q.empty()){
        node top = Q.top();
        int u = top.u;
        for(int i=0; i<(int)v[u].size(); i++){
            // write the code here....
        }
    }
    return ;
}


int main(){
    return 0;
}

