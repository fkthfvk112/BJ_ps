#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define PAIR pair<int, int>
#define INF 100000

//���ͽ�Ʈ�� �˰����� �̿�. ������������ �������������� �ִܰŸ��� ������������ �� �������������� �Ÿ��� �� �� �ִ밪 ��ȯ
using namespace std;
vector<int> ans;//node 1 = 0
int partyPlace;
struct edge {
    int src, dest, weight;
};

class Graph {
public:
    vector<vector<PAIR>> adList;
    Graph(vector<edge> edges, int nodeNum) {
        adList.resize(nodeNum);
        for (auto edge : edges) {
            adList[edge.src].push_back(make_pair(edge.dest, edge.weight));
        }
    }
};

void dijkstra(Graph graph, int nodeNum, int startNode) {
    vector<vector<PAIR>> adList = graph.adList;
    priority_queue<PAIR> pq;
    vector<int> d(nodeNum, INF);
    d[startNode] = 0;
    pq.push(make_pair(0, startNode));
    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDis = -pq.top().first;//src���� ��������� �Ÿ�
        for (int i = 0; i < adList[current].size(); i++) {//���� ����� ��� ��� ����
            int next = adList[current][i].first;
            int nextDis = currentDis + adList[current][i].second;//current ����ϱ�!!
            if (nextDis < d[next]) {
                d[next] = nextDis;
                pq.push(make_pair(-nextDis, next));
            }
        }
        pq.pop();
    }
    if (startNode == partyPlace) {
        for (int i = 0; i < nodeNum; i++) {
            ans[i] += d[i];
        }
    }
    else {
        ans[startNode] += d[partyPlace];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum >> partyPlace;
    partyPlace--;
    ans.resize(nodeNum);
    vector<edge> edges;
    for (int i = 0; i < edgeNum; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back(edge{ src - 1, dest - 1, weight });
    }


    Graph graph = Graph(edges, nodeNum);

    for (int i = 0; i < nodeNum; i++) {
        dijkstra(graph, nodeNum, i);
    }

    cout<<*max_element(ans.begin(), ans.end());

    return 0;
}
