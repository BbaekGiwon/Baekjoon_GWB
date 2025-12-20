#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int INF = 1e9;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    
    for(int i=1; i<=n; i++) {
    	for(int j=1; j*j<=i; j++) {
    		dp[i] = min(dp[i], dp[i-j*j] + 1);
		}
	}

    cout << dp[n] << "\n";
    return 0;
}

