#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isGroupWord(string s){
    vector<char> prechars;
    for(int i = 0; i < s.length(); i++){
        if(i == 0 || s[i] == s[i-1]){
            prechars.push_back(s[i]);
            continue;
        }

        for(char c:prechars){
            if(c == s[i]) return false;
        }
        prechars.push_back(s[i]);
    }
    return true;
}

int main(){
    int n;
    int cnt = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;
        if(isGroupWord(s))cnt++;
    }
    cout<<cnt;
return 0;
}
