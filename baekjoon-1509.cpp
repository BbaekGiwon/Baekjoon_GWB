#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    vector<int> dp(n, INT_MAX);

    // 팰린드롬 여부 사전 계산
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len <= 2 || isPalindrome[i + 1][j - 1])) {
                isPalindrome[i][j] = true;
            }
        }
    }

    // DP로 최소 분할 계산
    for (int i = 0; i < n; i++) {
        if (isPalindrome[0][i]) {
            dp[i] = 0;
        } else {
            for (int j = 0; j < i; j++) {
                if (isPalindrome[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    
    cout << dp[n-1]+1 << endl;
    return 0;
}

