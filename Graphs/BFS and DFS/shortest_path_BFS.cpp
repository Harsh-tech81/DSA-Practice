#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <unordered_set>
using namespace std;
vector<list<int>> graph; // array of list (Adjacency List representation of the graph)
int v;
unordered_set<int> visited;
void add_edge(int src, int dest, bool bi_dir = true)
{
    graph[src].push_back(dest);
    if (bi_dir)
    {
        graph[dest].push_back(src);
    }
}
void bfs(int src, vector<int> &dist)
{
    queue<int> q;
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    q.push(src);
    while (!q.empty())
    {
        int curr = q.front();
        cout<<curr<<"  ";
        q.pop();
        for (auto neighbour : graph[curr])
        {
            if (!visited.count(neighbour))
            {
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
    cout<<endl;
}

int main()
{
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    while (e--)
    {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    int x;
    cin >> x;
    vector<int> dist;
    bfs(x, dist);
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << "  ";
    }

    return 0;
}