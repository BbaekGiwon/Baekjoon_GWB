#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	vector<int> S(N);
	for(int i=0; i<N; i++) cin >> S[i];
	
	int cnt[10] = {0};
	int kind = 0;
	int ans = 0;
	
	int l = 0;
	for(int r=0; r<N; r++) {
		if(cnt[S[r]] == 0) kind++;
		cnt[S[r]]++;
		
		while(kind > 2) {
			cnt[S[l]]--;
			if(cnt[S[l]] == 0) kind--;	
			l++;
		}
		
		ans = max(ans, r-l+1);
	}
	
	cout << ans;
	
	return 0;
}
