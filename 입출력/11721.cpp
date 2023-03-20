#include <iostream>

using namespace std;

int main(){
    string s1, buffer="";
    cin>>s1;
    int cnt;
    for(int i = 1; i <= s1.size(); i ++){
        buffer += s1[i-1];
        if(i%10 == 0){
            cout<<buffer<<endl;
            buffer = "";
        }
    }
    cout<<buffer<<endl;
return 0;
}
