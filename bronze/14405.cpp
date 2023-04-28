#include <iostream>
#include <string>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string word;
    cin>>word;

    string temp = "";
    int isAns = 1;
    for(int i = 0; i < word.size(); i++){
        temp += word[i];
        if(temp.length()==2){
            if(temp == "pi" || temp == "ka"){
                temp="";
            }
        }
        else if(temp.length() == 3){
            if(temp == "chu"){
                temp = "";
            }
            else{
                isAns = 0;
                break;
            }
        }
    }
    if(temp.length() >= 1) isAns = 0;
    if(isAns){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

return 0;}
