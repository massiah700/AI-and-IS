#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int color[], const vector<vector<int>> &graph, int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (graph[node][k] && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, const vector<vector<int>> &graph, int m, int n, int color[])
{
    if (node == n)
        return true;

    for (int col = 1; col <= m; col++)
    {
        if (isSafe(node, color, graph, n, col))
        {
            color[node] = col;
            if (solve(node + 1, graph, m, n, color))
                return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

void printSolution(int color[], int n)
{
    cout << "Color assignments:\n";
    for (int i = 0; i < n; i++)
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
}

int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter adjacency matrix of the graph:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter number of colors (M): ";
    cin >> m;

    int color[n] = {0};

    if (solve(0, graph, m, n, color))
    {
        printSolution(color, n);
    }
    else
    {
        cout << "No solution exists using " << m << " colors.\n";
    }

    return 0;
}
