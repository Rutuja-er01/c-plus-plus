// Practical No. 7: Graph representation and traversal
// Adjacency Matrix + Adjacency List, BFS (using list) and DFS (using matrix)
// Locations: A B C D E F    Routes: A-B, A-C, B-D, B-E, C-F, E-F

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 6;                       // number of locations (vertices)
char names[N] = {'A', 'B', 'C', 'D', 'E', 'F'};

int matrix[N][N];                      // adjacency matrix
vector<int> adjList[N];                // adjacency list

// Add a route (edge) between two locations in BOTH representations
void addEdge(int u, int v) {
    matrix[u][v] = 1;                  // undirected graph -> both sides
    matrix[v][u] = 1;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

// ---------- DISPLAY ADJACENCY MATRIX ----------
void showMatrix() {
    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < N; i++)
        cout << names[i] << " ";
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << names[i] << "  ";
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// ---------- DISPLAY ADJACENCY LIST ----------
void showList() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < N; i++) {
        cout << names[i];
        for (int j = 0; j < (int)adjList[i].size(); j++)
            cout << " -> " << names[adjList[i][j]];
        cout << endl;
    }
}

// ---------- BFS using ADJACENCY LIST (queue) ----------
void BFS(int start) {
    bool visited[N] = {false};
    queue<int> q;

    visited[start] = true;             // mark start visited
    q.push(start);                     // insert into queue

    while (!q.empty()) {
        int u = q.front();             // remove vertex from front
        q.pop();
        cout << names[u] << " ";       // visit / display

        for (int i = 0; i < (int)adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (!visited[v]) {         // unvisited neighbour
                visited[v] = true;     // mark visited
                q.push(v);             // add to queue
            }
        }
    }
    cout << endl;
}

// ---------- DFS using ADJACENCY MATRIX (recursion) ----------
bool visitedDFS[N];

void DFS(int u) {
    visitedDFS[u] = true;              // mark visited
    cout << names[u] << " ";           // display

    for (int v = 0; v < N; v++) {
        if (matrix[u][v] == 1 && !visitedDFS[v])   // connected & unvisited
            DFS(v);                    // go deeper
    }
}

int main() {
    // Routes: A-B, A-C, B-D, B-E, C-F, E-F   (A=0, B=1, C=2, D=3, E=4, F=5)
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(4, 5);

    showMatrix();
    showList();

    cout << "\nBFS (Adjacency List) starting from A: ";
    BFS(0);

    for (int i = 0; i < N; i++)
        visitedDFS[i] = false;
    cout << "DFS (Adjacency Matrix) starting from A: ";
    DFS(0);
    cout << endl;

    return 0;
}