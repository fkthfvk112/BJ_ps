#include <iostream>
#include <string>

using namespace std;

int main(){
int t;
string inputString;
int a, b;
cin>>t;
for(int i = 0; i < t; i++){
    cin>>inputString;
    string temp = "";
    for(int j =0; j < inputString.size();j++){
        temp+=inputString[j];
        if(inputString[j] == ','){
            a = stoi(temp);
            temp = "";
            continue;
        }
    }
    b = stoi(temp);
    cout<<a+b<<endl;
}
return 0;
}
