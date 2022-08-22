#include<bits/stdc++.h>
using namespace std;

#define MX 10000

vector < int > graph[MX];
bool vis[MX];
int dist[MX];

vector <int> v;

void bfs(int source){
    queue < int > Q;
     v.push_back(source);
    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.front();

        Q.pop();

        for (int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];
            if (vis[next] == 0){
                v.push_back(next);
                vis[next] = 1;
                dist[next] = dist[node] + 1;
                Q.push(next);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 1; i <= edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source;
    cin >> source;

    bfs(source);

    for(int i=1;i<=nodes;i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}