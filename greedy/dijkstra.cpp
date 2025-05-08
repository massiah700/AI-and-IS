#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (distance, node)

void dijkstra(int start, const vector<vector<pii>> &graph, int n)
{
    vector<int> dist(n, INT_MAX);                      // Distance from source to each node
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        for (auto edge : graph[currNode])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[neighbor] > currDist + weight)
            {
                dist[neighbor] = currDist + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "To node " << i << ": ";
        if (dist[i] == INT_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << endl;
    }
}

int main()
{
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<pii>> graph(n); // Adjacency list

    cout << "Enter edges in format (u v weight):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Remove this line for directed graph
    }

    int start;
    cout << "Enter the source node: ";
    cin >> start;

    dijkstra(start, graph, n);

    return 0;
}
