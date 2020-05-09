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

bool bicolorable(int s) {
    queue<int>  Q;
    Q.push(s);
    color[s] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i = 0;i <(int)v[u].size();i++){
            int uu=v[u][i];
            if(color[uu]==0){
                Q.push(uu);
                // color HEre
                color[uu]=3-color[u];
            }
            else if(color[uu] != color[u])
                continue;
             else {
                return false;
            }
        }
    }

}

int main() {

    return 0;
}
