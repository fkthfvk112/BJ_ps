#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int cost = 0;
        for (int j = 0; j < k; j++) {
            int element;
            cin >> element;
            pq.push(element);
        }
        while (pq.size() > 1) {
            int temp1, temp2;
            temp1 = pq.top();
            pq.pop();
            temp2 = pq.top();
            pq.pop();
            cost += temp1 + temp2;
            pq.push(temp1 + temp2);
        }
        cout << cost << endl;
        pq.pop();
    }
    return 0;
}
