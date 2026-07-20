/*
🔷 Problem 6: Kruskal’s Algorithm (MST using Disjoint Sets)
Select edges in order of increasing weight and add if they don't form a cycle.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int u, v, weight;
    Edge(int a, int b, int w) : u(a), v(b), weight(w) {}
};

bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

class Kruskal
{
    vector<int> parent;

    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[b] = a;
    }

public:
    void kruskalMST(vector<Edge> &edges, int V)
    {
        parent.resize(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;
        sort(edges.begin(), edges.end(), cmp);
        int totalWeight = 0;

        for (auto e : edges)
        {
            if (find(e.u) != find(e.v))
            {
                unionSet(e.u, e.v);
                totalWeight += e.weight;
            }
        }
        cout << "Total Weight of MST: " << totalWeight << "\n";
    }
};

int main()
{
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    Kruskal obj;
    obj.kruskalMST(edges, 4);
    return 0;
}
