#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int palindrome1(int mid, string s) {//��ĭ ������ �������� �Ӹ������ ���� �� ������ �ּ� �� ��ȯ
    int left = mid - 1;
    int right = mid + 1;
    int ans = s.size()*2 - 1;
    if (left < 0 || right > s.size() - 1) return ans;
    while (s[left] == s[right]){
        if (right == s.size() - 1 || left == 0) {
            ans = s.size() + left;
            break;
        }
        left--;
        right++;
    }
    return ans;
}

int palindrome2(int mid, string s) {//���� �������� �Ӹ���� ���� �� ������ �ּ� �� ��ȯ
    int left = mid-1;
    int right = mid;
    int ans = s.size() * 2 - 1;
    if (left < 0 || right > s.size() - 1) return ans;
    while (s[left] == s[right]) {
        if (right == s.size() - 1||left == 0) {
            ans = s.size() + left;
            break;
        }
        left--;
        right++;
    }
    return ans;
}
int main() {
    string s;
    cin >> s;
    int minNum = s.size() * 2-1;//�������� ��� ������ �ִ밪
    for (int mid = s.size() / 2; mid <= s.size() - 1; mid++) {//mid���� 1�� ���ذ��� Ȯ��
        int tempAns1 = palindrome1(mid, s);
        int tempAns2 = palindrome2(mid, s);
        int tempAns = min(tempAns1, tempAns2);
        if (minNum > tempAns) {//�ּҰ� ����
            minNum = tempAns;
        }
    }

    cout << minNum;
    return 0;
}
