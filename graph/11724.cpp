//visited배열을 돌면서 방문하지 않은 노드를 시작점으로 지정. visited가 모두 끝날 때까지 반복. visited 방문 시마다 cnt +1;

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge{
    int start, dest;
};

vector<bool> visited;
class Graph{
    public:
    vector<vector<int>> adList;
    Graph(vector<edge> edges, int nodeCnt){
        adList.resize(nodeCnt);
        for(auto ed:edges){
            adList[ed.start].push_back(ed.dest);
            adList[ed.dest].push_back(ed.start);
        }
    }

    queue<int> q;
    void bfs(int startNode){
        q.push(startNode);
        visited[startNode] = true;
        while(!q.empty()){
            int now = q.front();
            //cout<<now<<" ";
            for(auto next: adList[now]){
                if(visited[next] == false){
                    visited[next] = true;
                    q.push(next);
                }
            }
            q.pop();
        }
        //cout<<"\n";
    }
};

int main(){
    vector<edge> edges;
    int nodeCnt, edgeCnt, ans = 0;
    cin>>nodeCnt>>edgeCnt;
    visited.resize(nodeCnt+1);
    fill(visited.begin(), visited.end(), 0);

    for(int i = 0; i < edgeCnt; i++){
        int start, dest;
        cin>>start>>dest;
        edges.push_back(edge{start, dest});
    }

    Graph graph = Graph(edges ,nodeCnt+1);
    for(int i = 1; i <= nodeCnt; i++){
        if(visited[i] == true) continue;
        graph.bfs(i);
        ans++;
    }

    cout<<ans;


return 0;
}
