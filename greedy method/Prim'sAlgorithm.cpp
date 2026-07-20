/*
🔷 Problem 5: Prim's Algorithm (Minimum Spanning Tree)
Find MST of a graph using greedy approach. Always add minimum weight edge that
connects a new vertex.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

class Prim
{
public:
    void primMST(vector<vector<pii>> &graph, int V)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<bool> visited(V, false);
        pq.push({0, 0});
        int totalWeight = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            totalWeight += wt;

            for (auto [w, v] : graph[u])
            {
                if (!visited[v])
                    pq.push({w, v});
            }
        }
        cout << "Total Weight of MST: " << totalWeight << "\n";
    }
};

int main()
{
    int V = 5;
    vector<vector<pii>> graph(V);
    graph[0] = {{2, 1}, {3, 3}};
    graph[1] = {{2, 0}, {4, 2}, {3, 4}};
    graph[2] = {{4, 1}, {5, 3}};
    graph[3] = {{3, 0}, {5, 2}, {7, 4}};
    graph[4] = {{3, 1}, {7, 3}};
    Prim obj;
    obj.primMST(graph, V);
    return 0;
}
