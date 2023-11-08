#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void bi_search(const vector<int>& v1, int start, int end, int val) {
    if (start > end) {
        cout << 0 << "\n";
        return;
    }

    int mid = (start + end) / 2;

    if (v1[mid] == val) {
        cout << 1 << "\n";
        return;
    }


    if (val < v1[mid]) {
        return bi_search(v1, start, mid - 1, val);
    }
    else {
        return bi_search(v1, mid+1, end, val);
    }
}


int main() {
    int n, m;

    vector<int> v1;
    vector<int> v2;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v1.push_back(val);
    }

    sort(v1.begin(), v1.end());


    cin >> m;
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        v2.push_back(val);
    }


    for (int i = 0; i < v2.size(); i++) {
        bi_search(v1, 0, v1.size() - 1, v2[i]);
    }

    return 0;
}
