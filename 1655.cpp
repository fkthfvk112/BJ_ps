#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> leftQueue;
priority_queue<int, vector<int>, greater<int>> rightQueue;


int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        rightQueue.push(val);
        if (i == 0) {
            cout << val << endl;
            continue;
        }
        int leftSize = leftQueue.size();
        int rightSize = rightQueue.size();

        while (!(leftSize == rightSize || leftSize - rightSize == 1)) {
            int rightTop = rightQueue.top();
            rightQueue.pop();
            leftQueue.push(rightTop);

            leftSize = leftQueue.size();
            rightSize = rightQueue.size();
        }

        cout <<leftQueue.top() << endl;

    }

    return 0;
}
