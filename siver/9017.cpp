#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 201
using namespace std;

vector<int> nums;
int fifth[MAX];
long long int ans[MAX] = { 0, };

void preprocess(int peopleNum) {

    for (int i = 0; i < peopleNum; i++) {
        int cnt = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (i == nums[j]) cnt++;
            if (cnt == 4) {
                fifth[i] = j;
            }
            if (j == nums.size() - 1) {
                if (cnt < 5) {
                    for (auto itr = nums.begin(); itr < nums.end(); itr++) {
                        if (*itr == i) {
                            itr = nums.erase(itr);
                            itr--;
                        }
                    }
                }
            }

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            nums.push_back(num - 1);
        }

        preprocess(n);
        int numSize = nums.size();
        for (auto teamNum : nums) {
            ans[teamNum] += numSize;
            numSize--;
        }
        int maxAns = 0;
        int maxFif = 0;
        int ansTeamName= -1;


        for (int i = 0; i < nums.size(); i++) {
            if (ans[i] > maxAns) {
                maxAns = ans[i];
                maxFif = fifth[i];
                ansTeamName = i;
            }
            else if (maxAns == ans[i] && maxFif < fifth[i]) {
                maxAns = ans[i];
                ansTeamName = i;
            }
        }
        cout << ansTeamName + 1 << '\n';
    }


    return 0;
}
