#include <iostream>
#include <vector>
#include <queue>
#include <string>
//https://codecollector.tistory.com/1184
using namespace std;

int r, c;
queue<pair<int, int>> waterQueue;
queue<pair<int, int>> tempWaterQueue;
queue<pair<int, int>> swanQueue;
vector<string> field(r);
vector<vector<bool>> check(r, vector<bool>(c, 0));

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

//매 순간 물을 녹이고 하나의 백조를 bfs를 돌아 만날 수 있는지 아닌지 확인하는 알고리즘으로 진행
bool swanCanMeet(){
    queue<pair<int, int>> q;
    pair<int, int> now = swanQueue.front();

    while(!swanQueue.empty())
    for(int i = 0; i < 4; i++){
        int nx = now.first + dx[i];
        int ny = now.second + dy[i];
        bool canGo = (nx >= 0 && nx < c && ny >= 0 && ny < r);
        if(canGo){
            if(check[nx][ny] == true) continue;
            if(field[nx][ny] == 'L') return true;
            if(field[nx][ny] == '.') q.push(make_pair(nx, ny));
            if(field[nx][ny] == 'X') swanQueue.push(make_pair(nx, ny));
            check[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    return false;
}

int main(void) {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> field[i];
        for (int j = 0; j < c; j++) {
            if (field[i][j] == '.') {
                waterQueue.push({ i, j });
            }
            else if (field[i][j] == 'L') {
                swanQueue.push({ i, j });
            }
        }
    }

    return 0;
}
