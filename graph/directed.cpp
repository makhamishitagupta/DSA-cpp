#include <bits/stdc++.h>
using namespace std;

// directed graph
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool isCycle(vector<bool> &visited, vector<bool> &recStack, int v)
    {
        if (!visited[v])
        {
            visited[v] = true;
            recStack[v] = true;

            for (int neighbor : adj[v])
            {
                if (!visited[neighbor] && isCycle(visited, recStack, neighbor))
                    return true;
                else if (recStack[neighbor])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }

    // topological sort using DFS
    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack)
    {
        visited[v] = true;

        for (int neighbor : adj[v])
        {
            if (!visited[neighbor])
                topologicalSortUtil(neighbor, visited, Stack);
        }

        Stack.push(v);
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(5, 2);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<bool> visited(6, false);
    vector<bool> recStack(6, false);

    if (g.isCycle(visited, recStack, 0))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    stack<int> Stack;
    fill(visited.begin(), visited.end(), false);

    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
            g.topologicalSortUtil(i, visited, Stack);
    }

    cout << "Topological Sort: ";
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }

    return 0;
}