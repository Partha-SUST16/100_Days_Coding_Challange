#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[110], store;
bool color[110];

void read()
{
    for(int i=1; i<=110; i++) graph[i].clear();
    int u, v;
    while(m--)
    {
        scanf("%d %d" ,&u, &v);
        graph[u].push_back(v);
    }
    return ;
}


void dfs(int u)
{
    //printf("now at, u: %d\n", u);getch();
    color[u] = true;
    for(int i=0; i<(int)graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(color[v]==0)
            dfs(v);
    }
    store.push_back(u);
    //printf("pushed, u: %d\n", u);getch();
    return ;
}

int main()
{
    int test_cases;
    while(~scanf("%d %d", &n, &m) && (n|m))
    {
        read();
        memset(color, 0, sizeof color);
        store.clear();
        for(int i=1; i<=n; i++)
        {
            if(color[i]==0)
            {
                dfs(i);
            }
        }
        if(store.size())
            printf("%d", store[store.size()-1]);
        for(int i = store.size()-2; i>=0; i--)
            printf(" %d", store[i]);
        puts("");
    }
    return 0;
}

/*
7 10
1 3
1 4
3 6
4 6
4 3
2 4
2 5
5 4
4 7
5 7
*/
