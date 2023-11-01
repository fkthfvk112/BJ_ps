#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;
vector<vector<int>> tree;
int parent[MAX];
bool visited[MAX];

void bfs(int startNode){
    for(int node:tree[startNode]){
        if(visited[node] == false){
            visited[node] = true;
            parent[node] = startNode;
            bfs(node);
        }
    }
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int node1; int node2;
        cin >> node1 >> node2;

        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    visited[0] = true;
    visited[1] = true;

    bfs(1);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] <<"\n";
    }

    return 0;
}
