#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int MAX = 100;  // Maximum number of vertices
vector<int> adj[MAX]; // Adjacency list
bool visited[MAX];

// Add edge to the graph
void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected graph
}

// Recursive DFS
void dfs(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : adj[vertex])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

// Iterative BFS
void bfs(int start)
{
    fill(visited, visited + MAX, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adj[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Main Menu
int main()
{
    int choice, u, v, start, vertices;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    do
    {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. DFS Traversal\n";
        cout << "3. BFS Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter two vertices (u v): ";
            cin >> u >> v;
            addEdge(u, v);
            break;

        case 2:
            cout << "Enter starting vertex for DFS: ";
            cin >> start;
            fill(visited, visited + MAX, false); // Reset visited array
            cout << "DFS: ";
            dfs(start);
            cout << endl;
            break;

        case 3:
            cout << "Enter starting vertex for BFS: ";
            cin >> start;
            cout << "BFS: ";
            bfs(start);
            cout << endl;
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
