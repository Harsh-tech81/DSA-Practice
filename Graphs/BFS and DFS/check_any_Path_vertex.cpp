#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;
vector<list<int>> graph; // array of list
int v;                   // No. of Vertices
unordered_set<int> visited;
void add_edge(int src, int dest, bool bi_dir = true)
{
    graph[src].push_back(dest);
    if (bi_dir)
    {
        graph[dest].push_back(src);
    }
}
bool dfs(int curr, int end)
{
    if(curr==end) return true;  // if curr reaches at the end then return true means there is a path exist from curr to end 
    visited.insert(curr); // mark visited
    for (auto neighbour : graph[curr])
    {
        if (!visited.count(neighbour))
        {
            bool result = dfs(neighbour, end);
            if (result)
                return true;
        }
    }
    return false;
}

bool anyPath(int src, int dest)
{
    return dfs(src, dest);
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
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<endl;
    return 0;
}