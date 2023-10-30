#include <iostream>
#include <vector>

using namespace std;
int maxValue = 0;
int n, k;

struct thing{
    int w;
    int v;
};

void getMaxValue(vector<thing> bag, int valueNow, int weightNow, int index){
    if(index > n||weightNow > k) return;//종료 조건
    if(valueNow > maxValue){
        maxValue = valueNow;
    }
    getMaxValue(bag, valueNow+bag[index].v, weightNow+bag[index].w, index+1);
    getMaxValue(bag, valueNow, weightNow, index+1);
}

int main(void){
    vector<thing> bag;
    cin>>n>>k;

    int w, v;
    for(int i = 0; i < n; i++){
        cin>>w>>v;
        bag.push_back({w, v});
    }

    getMaxValue(bag, 0, 0, 0);

    cout<<maxValue;
return 0;
}
