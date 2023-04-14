#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int path[10][10];
int pass[10][10];

using namespace std;

void floyd() {
    for (int passby = 1; passby <= 6; passby++) {
        for (int start = 1; start <= 6; start++) {
            for (int dest = 1; dest <= 6; dest++) {
                if (start == dest)path[start][dest] = 0;
                if (path[start][dest] > path[start][passby] + path[passby][dest]) {
                    path[start][dest] = path[start][passby] + path[passby][dest];
                    pass[start][dest] = pass[start][passby];
                }
            }
        }
    }
}

void findPath(int start, int dest){
    while(1){
        cout<<start<<" -> ";
        start = pass[start][dest];
        if(start == dest) break;
    }
    cout<<dest;
}
int main(void) {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            path[i][j] = 9999;
            pass[i][j] = j;
        }
    }

    path[1][2] = 1;
    path[2][4] = 2;
    path[2][5] = 4;
    path[4][5] = 2;
    path[5][6] = 1;
    path[3][6] = 16;
    path[3][1] = 5;
    path[6][3] = 1;
    floyd();

    cout << "After floyd" << endl;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (path[i][j]==9999) cout << "INF ";
            else cout << path[i][j] << "  ";
        }
        cout << '\n';
    }

    cout << "pass" << endl;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            cout << pass[i][j] << "  ";
        }
        cout << '\n';
    }

    findPath(2, 3);

    return 0;
}
