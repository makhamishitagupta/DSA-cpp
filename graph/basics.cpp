#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;
    vector<list<int>> l;

public:
    Graph(int v)
    {
        this->V = v;
        l.resize(v);
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int j : l[i])
            {
                cout << j << " ";
            }

            cout << endl;
        }
    }

    // connected graph BFS
    void bfs(int src) // O(V+E)
    {
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(src);
        visited[src] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            cout << u << " ";
            for (int v : l[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    // disconnected graph BFS
    void bfsHelper(int src, vector<bool> &visited)
    {
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v : l[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void bfs()
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bfsHelper(i, visited);
            }
        }
    }

    // connected graph DFS
    void dfs(int u, vector<bool> &visited)
    {
        cout << u << " ";
        visited[u] = true;

        for (int v : l[u])
        {
            if (!visited[v])
                dfs(v, visited);
        }
    }

    // disconnected graph DFS
    void dfsHelper(int u, vector<bool> &visited)
    {
        visited[u] = true;
        cout << u << " ";

        for (int v : l[u])
        {
            if (!visited[v])
                dfsHelper(v, visited);
        }
    }

    void dfs()
    {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsHelper(i, visited);
            }
        }
    }

    // using dfs
    bool isCycleDFS(int src, int par, vector<bool> visited)
    {
        visited[src] = true;

        for (int i : l[src])
        {
            if (!visited[i])
            {
                if (isCycleDFS(i, src, visited))
                {
                    return true;
                }
            }
            else if (i != par)
            {
                return true;
            }
        }

        return false;
    }

    bool isCycle()
    {
        vector<bool> visited(V, false);

        return isCycleDFS(0, -1, visited);
    }

    bool isCycleBFS()
    {
        vector<bool> visited(V, false);
        queue<pair<int, int>> q;

        q.push({0, -1});

        visited[0] = true;

        while (q.size() > 0)
        {
            int par = q.front().second;
            int u = q.front().first;

            q.pop();

            for (int v : l[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, u});
                }
                else if (v != par)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.printGraph();

    cout << "BFS : ";
    g.bfs(0);

    vector<bool> vis(5, false);
    cout << "DFS : ";
    g.dfs(0, vis);
    cout << endl;

    cout << "Is cycle? " << g.isCycle() << endl;
    cout << "Is cycle? " << g.isCycleBFS() << endl;

    return 0;
}