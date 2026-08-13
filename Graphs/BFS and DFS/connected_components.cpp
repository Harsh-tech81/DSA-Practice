#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
// count the no. of connected components 
using namespace std;
vector<list<int>> graph; // array of list
int v;                   // No. of Vertices
void add_edge(int src, int dest, bool bi_dir = true)  // by default we assume the graph is undirected 
{
    graph[src].push_back(dest);
    if (bi_dir)
    {
        graph[dest].push_back(src);
    }
}
void dfs(int node, unordered_set<int> &visited)
{
    visited.insert(node);
    for (auto neighbour : graph[node])
    {
        if (visited.find(neighbour) == visited.end())
        {
            dfs(neighbour, visited);
        }
    }
}
int connected_components()
{
    int res = 0;
    unordered_set<int> visited;
    for (int i = 0; i < v; i++)
    {
        // Go to every vertex
        // if from a vertex we can initialize a dfs , we got one more connected components
        if (visited.find(i) == visited.end())
        {
            res++;
            dfs(i, visited);
        }
    }
    return res;
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
        add_edge(s, d, false); 
    }
    cout << connected_components() << endl;

    return 0;
}