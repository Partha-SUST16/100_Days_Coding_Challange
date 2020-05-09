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
const int MAX = 105;
vector<int> g[MAX];
bool vis[MAX];


void dfs(int u){ ///u is any node of given moment
    vis[u] = true;
    for(int i =0;i <(int)g[u].size();++i)
        int v = g[u][i];
        if(vis[v]==false) {
                dfs(v);
        }
}

int main() {

    return 0;
}

