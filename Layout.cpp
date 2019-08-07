#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define int long long

const int N = 1e3+5, INF = 1e18+9;
int n, m, k, u, v, w, pos = 0;
int dist[N], visited[N];
vector<pair<int,int> > adj[N];
pair<pair<int,int>, int> edge[30*N];
queue<int> q;

signed main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(mp(v,w));
        edge[pos++] = mp(mp(u,v),w);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v >> w;
        adj[v].push_back(mp(u,-w));
        edge[pos++] = mp(mp(v,u),-w);
    }
    for (int i = 1; i <= n-1; i++)
    {
        adj[i+1].push_back(mp(i,0));
        dist[i+1] = INF;
        edge[pos++] = mp(mp(i+1,i),0);
    }
    dist[1] = 0;
    visited[1] = 1;
    q.push(1);
    /*

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int j = 0; j < adj[u].size(); j++)
        {
            pair<int,int> p = adj[u][j];
            int v = p.st, w = p.nd;
            if (dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                if (!visited[v])
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    */
    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < pos; i++)
        {
            int u = edge[i].st.st, v = edge[i].st.nd, w = edge[i].nd;
            if (dist[v] > dist[u]+w)
                dist[v] = dist[u]+w;
        }
    }

    for (int i = 0; i < pos; i++)
    {
        int u = edge[i].st.st, v = edge[i].st.nd, w = edge[i].nd;
        if (dist[v] > dist[u]+w)
            return cout << -1, 0;
    }
    if (dist[n] == INF)
        cout << -2;
    else
        cout << dist[n];
}
