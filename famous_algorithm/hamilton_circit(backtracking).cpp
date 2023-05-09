#include <iostream>
#include <vector>


using namespace std;

void hamiltonian(int i){
    int j;
    if(promising(i))}
        if(i == n-1){
            //print vindex[0] to vindex[n-1]
        } else{
        for(j = 2; j < n; j++){
            vindex[i+1] = j;
            hamiltonian(i+1);
        }
}

bool primissing(int i){
    int j;
    bool toggel;
    if(i == n-1 && (!w[vindex[i]][vindex[0])){//첫번째 정점과 마지막 정점은 연결되어야한다
        toggel = false;
    }
    else if(i>0 && (!w[vindex[i-1][vindex[i])){
        toggel = false; //i번째 정점은 i-1정점과 연결되어있어야한다.
    }else{
        toggle = true;
        j = 1;
        while(j < i && toggel){
            if(vindex[j] == vindex[i]) toggel = false;//i가 이미 방문한 노드인경우 false
            j++;
        }
    }
    return toggel;
}
