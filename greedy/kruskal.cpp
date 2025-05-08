#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n , 0);
        parent.resize(n );
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        vector<pair<int, pair<int, int>>> edgeList;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            edgeList.push_back({wt, {u, v}});
        }

        sort(edgeList.begin(), edgeList.end());

        DisjointSet ds(V);
        int mstWt = 0;
        for (auto it : edgeList)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;
                ds.unionByRank(u, v);
            }
        }

        return mstWt;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    Solution obj;
    int mstWt = obj.spanningTree(V, edges);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}
