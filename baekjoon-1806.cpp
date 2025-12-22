#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, S;
	cin >> N >> S;
	
	vector<int> num(N);
	for(int i=0; i<N; i++) cin >> num[i];
	
	int ans = 1e9;
	int hap = 0;
	int l = 0;
	for(int r=0; r<N; r++) {
		hap += num[r];
		
		if(hap<S) continue;
		
		while(l < r) {
			if(hap-num[l] >= S) {
				hap -= num[l];
				l++;
			}
			else break;
		}
		
		ans = min(ans, r-l+1);
	}
	
	if(ans == 1e9) cout << 0;
	else cout << ans;
	
	return 0;
}
