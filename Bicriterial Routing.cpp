// SPFA cai tuong tu nen cac ban tu lam nhe
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define time tim // tranh lap ten bien voi time co san trong may
struct adjList
{
    int v, cost, time;
    bool operator<(const adjList& rhs) const
    {
        return time > rhs.time; // sort theo chieu nguoc lai
    }
};

const int N = 105;
int n, m, s, t, u, v, cost, time, ans = 0;
int dist[N][N*N]; //dist[i][j] la thoi gian ngan nhat de den duoc nut i voi cost la j
vector<adjList> adj[N];
priority_queue<adjList> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> s >> t;
    int max_cost = (n-1)*100;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> cost >> time;
        adj[u].push_back({v,cost,time});
        adj[v].push_back({u,cost,time});
    }
    memset(dist,0x3f,sizeof dist); // khoi tao (INF = 0x3f)
    dist[s][0] = 0;
    pq.push({s,0,0});
    while(!pq.empty())
    {
        u = pq.top().v, cost = pq.top().cost, time = pq.top().time;
        pq.pop();
        if (dist[u][cost] == time)
        {
            for (int j = 0; j < adj[u].size(); j++)
            {
                adjList p = adj[u][j];
                if (cost + p.cost > max_cost) continue;
                if (dist[p.v][cost+p.cost] > dist[u][cost] + p.time)
                {
                    dist[p.v][cost+p.cost] = dist[u][cost] + p.time; // cap nhat
                    pq.push({p.v,cost+p.cost,dist[p.v][cost+p.cost]});
                }
            }
        }
    }
    int mn = max_cost + 5;
    for (int i = 0; i <= max_cost; i++)
    {
        if (dist[t][i] == 0x3f) continue;
        if (mn <= dist[t][i]) continue; // tim nhung cai better nhat
        mn = dist[t][i];
        ans++;
    }
    cout << ans;
}
