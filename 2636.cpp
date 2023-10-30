#include <iostream>
#include <vector>
#include <queue>
#define MAX_VAL 100

using namespace std;

struct point {
    int x;//j
    int y;//i
};

queue<point> tempQueue;
queue<point> processingQueue;
queue<point> saveQueue;

int dX[] = { -1, 0, 1, 0 };
int dY[] = { 0, -1, 0, 1 };

int main(void) {
    int tY, tX;
    cin >> tY >> tX;
    vector<vector<int>> table(tY, vector<int>(tX, 0));
    vector<vector<bool>> checked(tY, vector<bool>(tX, 0));
    int cheeseCnt = 0;
    int cheeseCheckCnt = 0;
    int day = 0;
    for (int i = 0; i < tY; i++) {
        for (int j = 0; j < tX; j++) {
            int num;
            cin >> num;
            table[i][j] = num;
            if(num == 1) cheeseCnt++;
        }
    }

    processingQueue.push({ 0, 0 });
    checked[0][0] = true;

    while (!processingQueue.empty()) {
        day++;
        while (!processingQueue.empty()) {//Ä¡Áî °ÑÀ» ³ìÀÌ´Â µ¿ÀÛ

            point now = processingQueue.front();
            checked[now.y][now.x] = true;
            table[now.y][now.x] = 0;
            processingQueue.pop();

            for (int i = 0; i < 4; i++) {
                int nextX = now.x + dX[i];
                int nextY = now.y + dY[i];

                bool canGoCondition = nextX >= 0 && nextX < tX&& nextY >= 0 && nextY < tY && !checked[nextY][nextX];
                if (canGoCondition) {
                    if (table[nextY][nextX] == 1) {
                        tempQueue.push({ nextX, nextY });
                        checked[nextY][nextX] = true;
                        cheeseCheckCnt++;

                    }
                    else {
                        processingQueue.push({ nextX, nextY });
                        checked[nextY][nextX] = true;
                    }
                }
            }
        }
        while (!tempQueue.empty()) {
            point nextPoint = tempQueue.front();
            processingQueue.push(nextPoint);
            saveQueue.push(nextPoint);
            tempQueue.pop();
        }

        if (cheeseCheckCnt == cheeseCnt) break;
        while (!saveQueue.empty()) {
            saveQueue.pop();
        }

    }

    int result = 0;
    while (!saveQueue.empty()) {
        saveQueue.pop();
        result++;
    }

    cout << day << "\n" << result;

    return 0;
}
