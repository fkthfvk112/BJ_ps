//인접 리스트로 무방향 그래프 구현 후 BFS 진행

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int src, dest;
};

class Graph{
public:
    vector<vector<int>> adList;
    Graph(vector<Edge> edges, int n){
        adList.resize(n);
        for(auto edge:edges){
            adList[edge.src].push_back(edge.dest);
            adList[edge.dest].push_back(edge.src);
        }
    }
    void printNode(){
        for(auto a:adList){
            for(auto b: a){
                cout<<b<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int nodeNum, edgeNum;
    cin>>nodeNum>>edgeNum;
    vector<Edge> edges;
    for(int i = 0; i < edgeNum; i++){
        int src, dest;
        cin>>src>>dest;
        edges.push_back(Edge{src, dest});
    }

    Graph graph = Graph(edges, nodeNum+1);// 0노드 건너뛰고 사용

    queue<int> q;
    vector<int> visited(nodeNum+1, 0);
    visited[0] = 1;//dont use zero index
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int nodeNow = q.front();
        for(auto next:graph.adList[nodeNow]){
            if(!visited[next]){
                q.push(next);
                visited[next] = 1;
                //cout<<"방문 : "<<next<<endl;
            }
        }
        q.pop();
    }

    int ans = 0;
    for(auto v:visited){
        if(v == 1) ans++;
    }
    cout<<ans-2;//except 0 and 1
return 0;
}
