#include <iostream>
#include <vector>


using namespace std;
int W;
vector<int> weights;
vector<bool> include;
int ans = 0;
bool isPromissing(int i, int weight, int total) {
    return weight == W || (weight + total >= W && weight + weights[i + 1] <= W);
}


void sumOfSubset(int i, int weight, int total) {//tatol ...남은 무게
    if (isPromissing(i, weight, total)) {
        if (weight == W) {
            ans ++;
        }
        else {
            include[i + 1] = true;
            sumOfSubset(i+1, weight + weights[i + 1], total - weights[i + 1]);
            include[i + 1] = false;
            sumOfSubset(i+1, weight, total - weights[i + 1]);
        }
    }
}
int main() {
    int n;
    cin >> n >> W;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        weights.push_back(weight);
        total += weight;
    }
    include.resize(weights.size());
    sumOfSubset(0, 0, total);
    cout<<ans;
    return 0;
}
