#include <iostream>
#include <string>

using namespace std;

bool isPalindrom(const string& s, int start, int end){
    while(1){
        if(start >= end) return true;
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
}

int main(){
    string s;
    cin>>s;
    int end = s.length();
    int tempAns = 0;
    for(int i =0 ; i < end; i++){
        if(isPalindrom(s, i, end-1)){
            break;
        }
        tempAns++;
    }

    cout<<tempAns+s.length();

return 0;
}
