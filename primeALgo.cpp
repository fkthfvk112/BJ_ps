#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
//2차원 인접 행렬이 아닌 리스트로 바꾸어서 풀기 1197

using namespace std;
class Edge {
public:
    int src, dest, weight;
    Edge(int _src, int _dest, int _weight) {
        src = _src;
        dest = _dest;
        weight = _weight;
    }
};

vector<vector<int>> makeGraph(int vSize, vector<Edge> edges) {
    vector<vector<int>> graph(vSize + 1, vector<int>(vSize + 1, 0));
    for (auto edge : edges) {
        graph[edge.src][edge.dest] = edge.weight;
        graph[edge.dest][edge.src] = edge.weight;
    }

    return graph;
}

bool isInChecked(int node, vector<int> checked) {
    bool isExist = find(checked.begin(), checked.end(), node) != checked.end();

    return isExist;
}
void prime(vector<vector<int>> graph, int v) {
    long long int ans = 0;

    vector<int> checked;
    checked.push_back(0);
    while (!(checked.size() == v)) {
        int min = INF;
        int candidat;
        int startingNode;
        for (int i = 0; i < checked.size(); i++) {//체크된 요소 중
            int nodeNow = checked[i];
            for (int j = 0; j < v; j++) {// 현재 요소가 방문 가능한 모든 경우 조사
                if (min > graph[nodeNow][j] && !isInChecked(j, checked) && graph[nodeNow][j] != 0) {
                    min = graph[nodeNow][j];
                    candidat = j;//최소값이 바뀌면 도착지점 j를 방문 후보로
                    startingNode = i;//ans 계산하기 위함
                }
            }
        }
        checked.push_back(candidat);
        //cout << "방문" << candidat+1 << "간선"<< graph[startingNode][candidat] << endl;
        ans += graph[startingNode][candidat];
    }
    cout << ans;
}
int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph;
    vector<Edge> edges;
    for (int i = 0; i < e; i++) {
        int v1, v2, edge;
        cin >> v1 >> v2 >> edge;
        edges.push_back(Edge(v1 - 1, v2 - 1, edge));
    }

    graph = makeGraph(v - 1, edges);


    prime(graph, v);
    return 0;

}
