// Shortest Path in Undirected Graph with Unit Weights
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<list<int>> adj(7);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(5);

    queue<pair<int, int>> q; // node, distace
    vector<int> dist(7, INT_MAX);
    q.push({0, 0});
    dist[0] = 0;

    while (!q.empty())
    {
        int src = q.front().first;
        int d = q.front().second;

        q.pop();

        for (auto v : adj[src])
        {
            if (dist[v] > d + 1)
            {
                dist[v] = min(dist[v], d + 1);
                q.push({v, d + 1});
            }
        }
    }

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX)
        {
            dist[i] = -1;
            cout << "Node " << i << " is not reachable from node 0" << endl;
        }
        else
            cout << "Minimum Distance from 0 to " << i << " is " << dist[i] << endl;
    }

    return 0;
}