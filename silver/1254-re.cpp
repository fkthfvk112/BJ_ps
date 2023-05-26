#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int palindrome1(int mid, string s) {//한칸 떨어진 지점에서 팰린드롬을 만들 수 있으면 최소 수 반환
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

int palindrome2(int mid, string s) {//붙은 지점에서 팰린드롬 만들 수 있으면 최소 수 반환
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
    int minNum = s.size() * 2-1;//문제에서 출력 가능한 최대값
    for (int mid = s.size() / 2; mid <= s.size() - 1; mid++) {//mid값을 1씩 더해가며 확인
        int tempAns1 = palindrome1(mid, s);
        int tempAns2 = palindrome2(mid, s);
        int tempAns = min(tempAns1, tempAns2);
        if (minNum > tempAns) {//최소값 선택
            minNum = tempAns;
        }
    }

    cout << minNum;
    return 0;
}
