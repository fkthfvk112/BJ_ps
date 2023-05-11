#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define MAX 101
#define rowCol pair<int, int>
using namespace std;
int maze[MAX][MAX] = {0,};
int n, m;//m row c col
priority_queue<pair<int, rowCol>> pq;//first wiehgt,


//push�� �� �湮 ó���� �Ͽ����Ѵ�. ó�� pop�Ҷ� �湮ó���� �ع����� �޸� �ʰ� �߻��߾���

void pushRouteToPq(rowCol now, int weight){
    int row = now.first;
    int col = now.second;
    int nextWeihgt = weight +1;

    if(row -1 >= 0 && maze[row-1][col] == 1){
        if(maze[row-1][col]==1||maze[row-1][col] > weight+1){
            pq.push({-nextWeihgt, {row-1, col}});//up
            maze[row-1][col]  = nextWeihgt;

        }
    }

    if(col+1 < m  && maze[row][col+1] == 1){
        if(maze[row][col+1]==1||maze[row][col+1] > weight+1){
            pq.push({-nextWeihgt, {row, col+1}});//right
            maze[row][col+1]  = nextWeihgt;

        }
    }
    if(row  +1 < n  && maze[row+1][col] == 1){
        if(maze[row+1][col] == 1||maze[row+1][col] > weight+1){
            pq.push({-nextWeihgt, {row+1, col}});//bottom
            maze[row+1][col]  = nextWeihgt;
        }
    }
    if(col -1 >= 0  && maze[row][col -1] == 1){
        if(maze[row][col -1]==1||maze[row][col -1] > weight+1){
            pq.push({-nextWeihgt, {row, col -1}});//left
            maze[row][col -1]  = nextWeihgt;
        }
    }
}

void findRoute(){
    rowCol now = {0, 0};
    maze[0][0] = 0;
    pushRouteToPq(now, 1);
    while(!pq.empty()){
        rowCol now = pq.top().second;
        int nowWeight = -pq.top().first;
        //maze[now.first][now.second]  = nowWeight;
        pq.pop();
        pushRouteToPq(now, nowWeight);
    }
}


int main(){
    string mazeRow;
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>mazeRow;
        for(int j = 0; j < m; j++){
            maze[i][j] = mazeRow[j] - '0';
        }
    }
    findRoute();

/*
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;

    }
*/
    cout<<maze[n-1][m-1];
return 0;
}
