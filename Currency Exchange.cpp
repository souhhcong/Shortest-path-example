#include <iostream>
#include <vector>
using namespace std;

#define float double
struct edgeList
{
    int u, v;
    float r, c;
};

const int N = 105;
const float EPSILON = 1e-6; // de phong sai so
int n, m, s;
float val, dist[N]; // dist[i]: so tien lon nhat thu duoc khi dang o nut i
int u, v;
float r1, c1, r2, c2;
vector<edgeList> edge;

int main()
{
    cin >> n >> m >> s >> val;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> r1 >> c1 >> r2 >> c2;
        edge.push_back({u,v,r1,c1});
        edge.push_back({v,u,r2,c2});
    }
    dist[s] = val; // init
    for (int i = 1; i <= n-1; i++)
    {
        for (auto e: edge)
        {
            dist[e.v] = max(dist[e.v],(dist[e.u]-e.c)*e.r); // bellman-ford tim duong di dai nhat
        }
    }
    for (auto e: edge)
    {
        if (dist[e.v]+EPSILON < (dist[e.u]-e.c)*e.r) // neu ton tai chu trinh duong
        {
            return cout << "YES", 0;
        }
    }
    cout << "NO"; // neu khong
}
