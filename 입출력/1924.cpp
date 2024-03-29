#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

        cout << leftQueue.top() << "\n";
    }

return 0;
}
