#include <iostream>
#include <vector>
#include <queue>
#define PAIR pair<int, int>
#define INF 100000
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
            adList[edge.dest].push_back(make_pair(edge.src, edge.weight));
        }
    }
};

void dijkstra(Graph graph, int nodeNum, int startNode) {
    vector<vector<PAIR>> adList = graph.adList;
    priority_queue<PAIR> pq;
    vector<int> d(nodeNum, INF);
    d[0] = 0;
    pq.push(make_pair(0, startNode));
    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDis = -pq.top().first;//src에서 현재까지의 거리
        for (int i = 0; i < adList[current].size(); i++) {//현재 노드의 모든 노드 조사
            int next = adList[current][i].first;
            int nextDis = currentDis + adList[current][i].second;//current 기억하기!!
            if (nextDis < d[next]) {
                d[next] = nextDis;
                pq.push(make_pair(-nextDis, next));
            }
        }
        pq.pop();
    }
    if(startNode != partyPlace) ans.push_back(d[partyPlace]);
    else{
        ans[startNode] += d[startNode];
    }
}

int main() {
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum >> partyPlace;
    vector<edge> edges;
    for (int i = 0; i < edgeNum; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back(edge{src-1, dest-1, weight });
    }

    Graph graph = Graph(edges, nodeNum);

    for(int i = 0; i < edgeNum; i++){
            dijkstra(graph, nodeNum, i);
            dijkstra(graph, nodeNum, i);
    }

    for(auto a: ans){
        cout<<a<<" ";
    }

    return 0;
}
