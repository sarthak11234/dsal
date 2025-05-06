#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node {
    string vertex;
    int time;
    node *next;
};

class adjmatlist {
    int m[10][10], n, i, j;
    char ch;
    string v[20];
    node *head[20];
    node *temp = NULL;

public:
    adjmatlist() {
        for (i = 0; i < 20; i++) {
            head[i] = NULL;
        }
    }

    void getgraph();
    void adjlist();
    void displaym();
    void displaya();
};

void adjmatlist::getgraph() {
    cout << "\nEnter number of cities (max. 20): ";
    cin >> n;
    cout << "\nEnter names of cities:\n";
    for (i = 0; i < n; i++)
        cin >> v[i];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "\nIs there a path between city " << v[i] << " and " << v[j] << "? (y/n): ";
            cin >> ch;
            if (ch == 'y') {
                cout << "Enter time required to reach " << v[j] << " from " << v[i] << " (in minutes): ";
                cin >> m[i][j];
            } else if (ch == 'n') {
                m[i][j] = 0;
            } else {
                cout << "\nUnknown entry, defaulting to 0.";
                m[i][j] = 0;
            }
        }
    }
    adjlist();
}

void adjmatlist::adjlist() {
    for (i = 0; i < n; i++) {
        node *p = new node;
        p->next = NULL;
        p->vertex = v[i];
        head[i] = p;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (m[i][j] != 0) {
                node *p = new node;
                p->vertex = v[j];
                p->time = m[i][j];
                p->next = NULL;
                if (head[i]->next == NULL) {
                    head[i]->next = p;
                } else {
                    temp = head[i];
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = p;
                }
            }
        }
    }
}

void adjmatlist::displaym() {
    cout << "\n\nAdjacency Matrix:\n\t";
    for (j = 0; j < n; j++) {
        cout << v[j] << "\t";
    }
    for (i = 0; i < n; i++) {
        cout << "\n" << v[i] << "\t";
        for (j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
    }
    cout << "\n";
}

void adjmatlist::displaya() {
    cout << "\n\nAdjacency List:\n";
    for (i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "Adjacency list not present\n";
            break;
        } else {
            cout << head[i]->vertex;
            temp = head[i]->next;
            while (temp != NULL) {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << "\n";
        }
    }

    cout << "\nPath and Time Required:\n";
    for (i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "Adjacency list not present\n";
            break;
        } else {
            temp = head[i]->next;
            while (temp != NULL) {
                cout << head[i]->vertex << " -> " << temp->vertex
                     << "\n   [time required: " << temp->time << " min]\n";
                temp = temp->next;
            }
        }
    }
}

int main() {
    int m;
    adjmatlist a;
    while (1) {
        cout << "\n\nEnter your choice:";
        cout << "\n1. Enter graph";
        cout << "\n2. Display adjacency matrix for cities";
        cout << "\n3. Display adjacency list for cities";
        cout << "\n4. Exit\n";
        cin >> m;

        switch (m) {
        case 1:
            a.getgraph();
            break;
        case 2:
            a.displaym();
            break;
        case 3:
            a.displaya();
            break;
        case 4:
            exit(0);
        default:
            cout << "\nUnknown choice. Please try again.";
        }
    }
    return 0;
}
