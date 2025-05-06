
#include <iostream>
using namespace std;

int main() {
    int n, i, j, k, row, col, mincost = 0, min;
    char op;

    cout << "Enter no. of vertices: ";
    cin >> n;

    int cost[n][n];
    int visit[n];

    // Initialize visited array
    for (i = 0; i < n; i++)
        visit[i] = 0;

    // Initialize cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = -1;

    // Input edges and weights
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            cout << "Do you want an edge between " << i + 1 << " and " << j + 1 << "? (y/n): ";
            cin >> op;
            if (op == 'y' || op == 'Y') {
                cout << "Enter weight: ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }
        }
    }

    // Prim's algorithm
    visit[0] = 1; // start from vertex 0

    for (k = 0; k < n - 1; k++) {
        min = 999;
        for (i = 0; i < n; i++) {
            if (visit[i] == 1) {
                for (j = 0; j < n; j++) {
                    if (visit[j] == 0 && cost[i][j] != -1 && cost[i][j] < min) {
                        min = cost[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }
        visit[col] = 1;
        mincost += min;
        cout << row + 1 << " -> " << col + 1 << endl;

        // Mark the edge as used
        cost[row][col] = cost[col][row] = -1;
    }

    cout << "\nMinimum Cost: " << mincost << endl;

    return 0;
}

