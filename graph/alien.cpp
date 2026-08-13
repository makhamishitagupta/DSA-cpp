// https://www.geeksforgeeks.org/problems/alien-dictionary/1
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack, vector<int> adj[])
{
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        if (!visited[adj[v][i]])
        {
            topologicalSortUtil(adj[v][i], visited, Stack, adj);
        }
    }

    Stack.push(v);
}

// we use topological sort to find the order of characters in the alien language
int main()
{
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4; // Number of characters in the alien language

    vector<int> adj[k];

    for (int i = 0; i < dict.size() - 1; i++)
    {
        // for (int j = i + 1; j < dict.size(); j++)
        // {
        string word1 = dict[i];
        string word2 = dict[i + 1];

        for (int k = 0; k < min(word1.length(), word2.length()); k++)
        {
            if (word1[k] != word2[k])
            {
                addEdge(adj, word1[k] - 'a', word2[k] - 'a');
                break;
            }
        }
        //}
    }

    stack<int> Stack;
    vector<bool> visited(k, false);

    for (int i = 0; i < k; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, Stack, adj);
        }
    }

    cout << "The order of characters in the alien language is: ";
    while (!Stack.empty())
    {
        cout << char(Stack.top() + 'a') << " ";
        Stack.pop();
    }

    return 0;
}