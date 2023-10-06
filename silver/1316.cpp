#include <iostream>
#include <vector>
#include <string>
//글자의 값이 바로 이전 글자와 다를 때, 해당 글자가 포함 된 문자 내에 해당 글자를 제외한 같은 글자가 존재하면 조건 통과 실패
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> words;

    int n;
    cin>>n;
    int ans = n;
    for(int i = 0; i < n; i++){
        string word;
        cin>>word;
        words.push_back(word);
    }
    for(int i = 0; i < words.size(); i++){
        string word = words[i];
        for(int j = 0; j < word.size(); j++){
            bool breakCondition = 0;
            if(j>=1 && word[j] != word[j-1]){
                for(int k = 0; k < j; k++){
                    if(word[k] == word[j]){
                        breakCondition = 1;
                    }
                }
            }
            if(breakCondition == 1){
                ans--;
                break;
            }
        }
    }

    cout<<ans;
return 0;
}
