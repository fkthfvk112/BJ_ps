#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, num = 1;
    cin>>n;
    for(int i = 0; i < n; i++){
        cout<<num<<"\n";
        num++;
    }

return 0;
}

//endl�� ����ߴ��� �ð� �ʰ��� ���Դ�.
//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); c��Ÿ�ϰ� c++��Ÿ���� ������� ���´�
//https://www.acmicpc.net/problem/15552
