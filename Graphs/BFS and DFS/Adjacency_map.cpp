#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<unordered_map<int,int>> graph; // array of list
int v;                              // No. of Vertices
void add_edge(int src, int dest, int wgt, bool bi_dir = true)
{
    graph[src][dest]=wgt;
    if (bi_dir)
    {
       graph[dest][src]=wgt;
    }
}
void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto el : graph[i])
        {
            cout << "("<<el.first << "  " << el.second <<") , ";
        }
        cout << endl;
    }
}
int main()
{
    cin >> v;
    graph.resize(v, unordered_map<int,int>());
    int e;
    cin >> e;
    while (e--)
    {
        int s, d, w;
        cin >> s >> d >> w;
        add_edge(s, d, w); // directed and undirected graph can be easily changed by changing the boolean value true or false
    }
    display();

    return 0;
}