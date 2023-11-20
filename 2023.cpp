#include <iostream>
#include <vector>
#include <math.h>
#define MAX 100000000

using namespace std;

int digit;

bool isPrime(int num){
    if(num < 2){
        return false;
    }
    for(int i = 2; i*i <= num; i++){//<=를 <로 하였음
        if(num%i == 0){
            return false;
        }
    }

    return true;
}

void getStrangePrime(int num, int depth){
    if(depth == digit){
        cout<<num<<endl;
        return;
    }
    num *= 10;
    for(int i = 1; i < 10; i+=2){
        int newNum = num + i;
        if(isPrime(newNum)){
            getStrangePrime(newNum, depth+1);
        }
    }
}

int main(){
    cin>>digit;
    int initPrime[] = {2, 3, 5, 7};
    for(int prime:initPrime){
        getStrangePrime(prime, 1);
    }

}
