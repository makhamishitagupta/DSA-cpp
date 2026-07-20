/*
🔷 Problem 7: Dijkstra’s Shortest Path
Find the shortest paths from a source node to all others in a weighted graph
using greedy approach.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

class Dijkstra
{
public:
    void shortestPath(vector<vector<pii>> &graph, int src, int V)
    {
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d > dist[u])
                continue;

            for (auto [w, v] : graph[u])
            {
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << ": " << dist[i] << "\n";
    }
};

int main()
{
    int V = 5;
    vector<vector<pii>> graph(V);
    graph[0] = {{1, 10}, {4, 5}};
    graph[1] = {{2, 1}, {4, 2}};
    graph[2] = {{3, 4}};
    graph[3] = {{0, 7}, {2, 6}};
    graph[4] = {{1, 3}, {2, 9}, {3, 2}};

    Dijkstra obj;
    obj.shortestPath(graph, 0, V);
    return 0;
}
