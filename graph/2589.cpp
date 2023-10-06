#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int height, width;
    int val;
    cin >> height >> width;
    vector<vector<char>> map(height, vector<char>(width));
    vector<int> ans;

    struct edge {
        int y;
        int x;
        int cost;
    };

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> map[i][j];
        }
    }

    queue<edge> q;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 'W') continue;
            vector<vector<bool>> checkList(height, vector<bool>(width));
            q.push({ i, j, 0 });
            int maxCost = 0;
            while (!q.empty()) {
                edge now = q.front();

                if (now.cost > maxCost) {
                    maxCost = now.cost;
                }
                //up
                if (now.y > 0 && map[now.y - 1][now.x] != 'W' && checkList[now.y - 1][now.x] != true) {

                    q.push({ now.y - 1, now.x, now.cost + 1 });
                    checkList[now.y - 1][now.x] = true;
                }
                //right
                if (now.x < width - 1 && map[now.y][now.x + 1] != 'W' && checkList[now.y][now.x + 1] != true) {

                    q.push({ now.y, now.x + 1, now.cost + 1 });
                    checkList[now.y][now.x + 1] = true;
                }
                //left
                if (now.x > 0 && map[now.y][now.x - 1] != 'W' && checkList[now.y][now.x - 1] != true) {
                    q.push({ now.y, now.x - 1, now.cost + 1 });
                    checkList[now.y][now.x - 1] = true;
                }
                //down
                if (now.y < height - 1 && map[now.y + 1][now.x] != 'W' && checkList[now.y + 1][now.x] != true) {
                    q.push({ now.y + 1, now.x, now.cost + 1 });
                    checkList[now.y + 1][now.x] = true;
                }
                q.pop();
            }
            ans.push_back(maxCost);
        }
    }

    int result = 0;
    for (int an : ans) {
        if (an > result) {
            result = an;
        }
    }

    cout << result;

    return 0;
}
