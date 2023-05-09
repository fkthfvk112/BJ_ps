#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
int nodeNum, m;

int ansNum = 0;

struct edge {
    int src, dest;
};

class Graph {
public:
    vector<vector<int>> adList;
    Graph(vector<edge> edges, int nodeNum) {
        adList.resize(nodeNum);
        for (auto edge : edges) {
            adList[edge.src].push_back(edge.dest);
            adList[edge.dest].push_back(edge.src);
        }
    }
};

void printVector(vector<int> v) {
    ansNum++;
    for (auto v1 : v) {
        cout << v1+1 << " ";
    }
    cout << '\n';
}

bool isPromissing(int node, int color, Graph graph) {
    if (node == -1) return true; // root node
    for (auto adjNode : graph.adList[node+1]) {
        if (adjNode > node) continue;
        if (ans[adjNode] == color) return false;
    }
    return true;
}

void m_coloring(int node, int color, Graph graph) {
    if (node == nodeNum-1) {
        printVector(ans);
    }
    else {
        for (int i = 0; i < m; i++) {
            if (isPromissing(node, i, graph)) {
                ans[node + 1] = i;
                m_coloring(node + 1, i, graph);
            }
        }
    }
}

int main() {
    int edgeNum;
    vector<edge> edges;
    cin >> nodeNum >> m >> edgeNum;
    for (int i = 0; i < edgeNum; i++) {
        int src, dest;
        cin >> src >> dest;
        edges.push_back(edge{ src-1, dest-1 });
    }
    for (int i = 0; i < nodeNum; i++) {
        ans.push_back(-1);
    }
    Graph graph = Graph(edges, nodeNum);
    m_coloring(-1, 0, graph);
    cout << ansNum;

    return 0;
}
