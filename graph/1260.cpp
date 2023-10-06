#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


struct edge {
    int start, dest;
};

class Graph {
public:
    vector<vector<int>> adList;
    Graph(vector<edge> edges, int n) {
        adList.resize(n + 1);
        for (auto edge : edges) {
            adList[edge.start].push_back(edge.dest);
            adList[edge.dest].push_back(edge.start);
        }

        for (auto& edges : adList) {
            sort(edges.begin(), edges.end());
        }
    }

    vector<int> visitedDfs;
    stack<int> s1;
    void dfs(int startPoint) {
        visitedDfs.resize(adList.size());
        fill(visitedDfs.begin(), visitedDfs.end(), 0);

        s1.push(startPoint);
        cout << startPoint << " ";
        while (!s1.empty()) {
            int now = s1.top();
            visitedDfs[now] = 1;
            for (int i = 0; i < adList[now].size(); i++) {
                if (visitedDfs[adList[now].at(i)] == false) {
                    cout << adList[now].at(i)<< " ";
                    s1.push(adList[now].at(i));
                    break;
                }
            }
            if (s1.top() == now) {
                s1.pop();
            }
        }
        cout << '\n';
    }

    vector<int> visitedBfs;
    queue<int> q1;
    void bfs(int startPoint) {
        visitedBfs.resize(adList.size());
        fill(visitedBfs.begin(), visitedBfs.end(), 0);
        visitedBfs[startPoint] = 1;
        q1.push(startPoint);
        while (!q1.empty()) {
            int now = q1.front();
            q1.pop();
            for (int i = 0; i < adList[now].size(); i++) {
                if (visitedBfs[adList[now].at(i)] == false) {
                    visitedBfs[adList[now].at(i)] = 1;
                    q1.push(adList[now].at(i));
                }
            }
            cout << now << " ";
        }
        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int nodeNum, edgeNum, startNode;
    vector<edge> edges;
    cin >> nodeNum >> edgeNum >> startNode;
    int edgeStart, edgeDest;

    for (int i = 0; i < edgeNum; i++) {
        cin >> edgeStart >> edgeDest;
        edges.push_back({ edgeStart, edgeDest });
    }
    Graph graph = Graph(edges, nodeNum);
    graph.dfs(startNode);
    graph.bfs(startNode);
    return 0;
}
