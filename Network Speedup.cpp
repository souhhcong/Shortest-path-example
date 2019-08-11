#include <iostream>
#include <queue>
using namespace std;

#define st first
#define nd second
#define int long long

struct q
{
    int v, d, num;
    bool operator < (const q& o) const
    {
        return d > o.d;
    }
};

const int N = 1e5+5, INF = 1e18+9;
int n, m, dev, u, v, w;
vector<pair<int,int> > adj[N];
int dist[N][20];
priority_queue<q> pq;

signed main()
{
    cin >> n >> m >> dev;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= dev; j++)
            dist[i][j] = INF; // init
    dist[1][0] = 0;
    pq.push({1,0,0});

    while(!pq.empty())
    {
        int u = pq.top().v, d = pq.top().d, num = pq.top().num;
        pq.pop();
        if (dist[u][num] != d)
            continue;
        for (auto p: adj[u])
        {
            int v = p.st, w = p.nd;
            for (int j = num; j <= dev; j++) // j-num la so may dat o canh noi <u,v>
            {
                if (dist[u][num] + (w>>(j-num)) < dist[v][j]) // w>>(j-num) <=> w*pow(2,num-j)
                {
                    dist[v][j] = dist[u][num]+(w>>(j-num));
                    pq.push({v,dist[v][j],j});
                }
            }
        }
    }
    cout << dist[n][dev];
}
/*
4 4 2
1 2 16
2 4 8
1 3 1
3 4 40
*/
