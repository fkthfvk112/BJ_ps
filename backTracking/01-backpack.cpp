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


int maxprofit = 0;
void sumOfSubset(int i, int profit, int weight) {//tatol ...남은 무게
    if (weight <= W && profit > maxprofit) {
        maxprofit = profit;
    }
    if (isPromissing(i)) {
        include[i + 1] = true;
        sumOfSubset(i+1, profit + p[i+1], weight + w[i+1]);
        include[i + 1] = false;
        sumOfSubset(i+1, profit, weight);
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
