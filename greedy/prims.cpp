#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<pair<int, int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);
        pq.push({0, 0}); // {weight, node}
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;

            vis[node] = 1;
            sum += wt;

            for (auto &neighbor : adj[node])
            {
                int adjNode = neighbor.first;
                int edW = neighbor.second;
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    vector<pair<int, int>> adj[V];
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    Solution obj;
    int sum = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}
