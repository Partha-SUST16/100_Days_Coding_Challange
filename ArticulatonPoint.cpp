#include <bits/stdc++.h>
#define N 100000 //maximum nodes
#define MAXX 100000
using namespace std;
#define SIZE 10006
using namespace std;

vector < vector <int> > g;
map < pair <int, int>, int > mp;

int vis[SIZE];
int dur[SIZE];
int low[SIZE];
int art[SIZE];
int counter;
int parent[SIZE];

int find_articulation(int x)
{
	int child;
	int y;
	counter++;
	vis[x] = 1;
	child = 0;
	dur[x] = low[x] = counter;
	for (int i = 0; i < g[x].size(); i++) {
		y = g[x][i];
		child++;
		if(vis[y] == 0) {///tree edge
			parent[y] = x;
			find_articulation(y);
			low[x] = min(low[x], low[y]);

			if(low[y] > dur[x]) {
				if(mp.count(make_pair(min(x, y), max(x, y))) == 0) {
					mp[make_pair(min(x, y), max(x, y))] = 1;
				}
			}
		}
		else {///back edge
			if(y != parent[x]) {
				low[x] = min(low[x], dur[y]);
			}
		}
	}

}

void reset()
{
}

vector<int>adj[MAXX];

bool visited[MAXX];
int parent[MAXX];
int low[MAXX];/// minimum discover time
int disc[MAXX];/// discover time
int tyme;bool isArticulationPoint[MAXX];
void dfs_articulation_point(int u)
{
   visited[u] = true;
   disc[u] = low[u] = ++tyme;
   int cntChild = 0,i;

   loop(i, SZ(adj[u]))
   {
       int v = adj[u][i];

       if( ! visited[v] )///this is tree edge
       {
           cntChild++;
           parent[v] = u;
           dfs_articulation_point(v);
           low[u] = min(low[u], low[v]);
           if(parent[u] != -1)/// child node u isnt root
           {
               if(low[v] >= disc[u])
               {
                   isArticulationPoint[u] = true;
               }
           }
       }
       else if(v != parent[u])
       {
           low[u] = min(low[u], disc[v]);
       }
   }
   if(parent[u] == -1)/// root edge
   {
       if(cntChild > 1)
       {
           isArticulationPoint[u] = true;
       }
   }
}

int main()
{

  return 0;
}
