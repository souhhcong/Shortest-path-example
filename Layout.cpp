//Bellman-Ford van AC neu ban luoi code SPFA
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define st first
#define nd second
#define mp make_pair //old C++ gay

const int N = 1e3+5, INF = 1e9+9;
int n, m, k, u, v, w, pos = 0;
int dist[N], cnt[N];
bool visited[N];
vector<pair<int,int> > adj[N];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;         // dist[v]-dist[u] <= w
        adj[u].push_back(mp(v,w));  // => dist[u]+w >= dist[v]
    }
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v >> w;         // dist[v]-dist[u] >= w
        adj[v].push_back(mp(u,-w)); // => dist[v]+(-w) >= dist[u]
    }
    for (int i = 1; i <= n-1; i++)
    {
        adj[i+1].push_back(mp(i,0));// dist[i+1] >= dist[i]
        dist[i+1] = INF;            // => dist[i+1]+0 >= dist[i]
    }

    dist[1] = 0;
    q.push(1);
    while(!q.empty()) // SPFA
    {
        int u = q.front();
        for (int j = 0; j < adj[u].size(); j++)
        {
            pair<int,int> p = adj[u][j];
            int v = p.st, w = p.nd;
            if (dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = 1;
                    cnt[v]++;
                    if (cnt[v] > n) // ton tai chu trinh am
                    {
                        return cout << -1, 0;
                    }
                }
            }
        }
        visited[u] = 0;
        q.pop();
    }
    if (dist[n] == INF)
        cout << -2;
    else
        cout << dist[n];
}
