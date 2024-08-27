#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

void BFS(vector<vector<int>> &G, int R){

    queue<int> Q;
    vector<bool> Visited(G.size(), false);

    Visited[R] = true;
    Q.push(R);
    cout << R << endl;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        
        for (int y : G[x]) {  // y is a neighbor of x
            if (!Visited[y]) {
                cout << y << " ";
                Visited[y] = true;
                Q.push(y);
            }
        }
        cout << endl;  // If you want to print a newline after processing each node
    }
}

void DFS(vector<vector<int>> &G, int R, vector<bool>&visited){

    visited[R] = true;
    cout << R << endl;

    for(int x :G[R]){
        if(!visited[x])
            DFS(G, x, visited);
    }
}

int main(void){
    vector<vector<int>> lst = {{1,2}, {2,3}, {3,0}, {2,1}};
    vector<bool> visited(lst.size(), false);

    BFS(lst, 0);
    DFS(lst, 0, visited);
}