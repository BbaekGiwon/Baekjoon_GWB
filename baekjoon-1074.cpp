#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, r, c;
	cin >> N >> r >> c;
	
	int res = 0; 
	while(N>=1) {
		int t = (1<<(N-1));
		
		if(r<t) {
			if(c<t) { // 1사분면 
				res += 0;
			}
			else { // 2 사분면 
				res += (1<<(2*N-2));
				c -= t;
			}
		}
		else {
			if(c<t) {  // 3 사분면 
				res += (1<<(2*N-1));
				r -= t;
			}
			else { // 4 사분면 
				res += (1<<(2*N-1)) + (1<<(2*N-2));
				r -= t;
				c -= t;
			}
		}
		
		N--;
	}
	
	cout << res;
}
