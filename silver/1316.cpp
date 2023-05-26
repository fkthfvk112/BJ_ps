#include <iostream>
#include <vector>
#include <string>
//������ ���� �ٷ� ���� ���ڿ� �ٸ� ��, �ش� ���ڰ� ���� �� ���� ���� �ش� ���ڸ� ������ ���� ���ڰ� �����ϸ� ���� ��� ����
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
