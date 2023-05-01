#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
//2���� ���� ����� �ƴ� ����Ʈ�� �ٲپ Ǯ�� 1197

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
        for (int i = 0; i < checked.size(); i++) {//üũ�� ��� ��
            int nodeNow = checked[i];
            for (int j = 0; j < v; j++) {// ���� ��Ұ� �湮 ������ ��� ��� ����
                if (min > graph[nodeNow][j] && !isInChecked(j, checked) && graph[nodeNow][j] != 0) {
                    min = graph[nodeNow][j];
                    candidat = j;//�ּҰ��� �ٲ�� �������� j�� �湮 �ĺ���
                    startingNode = i;//ans ����ϱ� ����
                }
            }
        }
        checked.push_back(candidat);
        //cout << "�湮" << candidat+1 << "����"<< graph[startingNode][candidat] << endl;
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
