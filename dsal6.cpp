#include <iostream>
using namespace std;

int cost[10][10], n;
int qu[10], front = 0, rear = 0;
int visitedBFS[10] = {0}, visitedDFS[10] = {0};
int stk[10], top = 0;

void bfs(int v) {
    cout << "The BFS of the Graph is:\n";
    visitedBFS[v] = 1;
    cout << v << " ";
    qu[rear++] = v;

    while (front < rear) {
        v = qu[front++];
        for (int j = 0; j < n; j++) {
            if (cost[v][j] == 1 && visitedBFS[j] == 0) {
                qu[rear++] = j;
                visitedBFS[j] = 1;
                cout << j << " ";
            }
        }
    }
    cout << endl;
}

void dfs(int v) {
    cout << "The DFS of the Graph is:\n";
    visitedDFS[v] = 1;
    cout << v << " ";
    stk[top++] = v;

    while (top > 0) {
        v = stk[--top];
        for (int j = n - 1; j >= 0; j--) {
            if (cost[v][j] == 1 && visitedDFS[j] == 0) {
                cout << j << " ";
                visitedDFS[j] = 1;
                stk[top++] = j;
            }
        }
    }
    cout << endl;
}

int main() {
    int m, i, j, v;

    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    cout << "\nEnter the edges (format: u v):\n";
    for (int k = 0; k < m; k++) {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1; // undirected graph
    }

    cout << "\nThe adjacency matrix is:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter initial vertex for BFS: ";
    cin >> v;
    bfs(v);

    cout << "Enter initial vertex for DFS: ";
    cin >> v;
    dfs(v);

    return 0;
}
