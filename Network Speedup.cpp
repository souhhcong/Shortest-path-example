#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

#define st first
#define nd second
#define int long long
#define float long double
struct q
{
    int v;
    float d;
int num;
    bool operator < (const q& o) const
    {
        return d > o.d;
    }
};

const int N = 1e5+5;
const float INF = 1e9+9;
int n, m, dev, u, v, w;
float pow[11] = {1, 2, 4,8,16,32,64,128,256,512,1024};
vector<pair<int,int> > adj[N];
float dist[N][20];
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
        int u = pq.top().v, num = pq.top().num;
float d = pq.top().d;
        pq.pop();
        if (dist[u][num] != d)
            continue;
        for (auto p: adj[u])
        {
            int v = p.st, w = p.nd;
            for (int j = num; j <= dev; j++) // j-num la so may dat o canh noi <u,v>
            {
                if (dist[u][num] + (1.0*w/pow[j-num]) < dist[v][j])
                {
                    dist[v][j] = dist[u][num]+(1.0*w/pow[j-num]);
                    pq.push({v,dist[v][j],j});
                }
            }
        }
    }
    cout << fixed << setprecision(2) << dist[n][dev];
}
