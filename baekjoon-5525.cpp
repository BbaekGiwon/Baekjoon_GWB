#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	
	int cnt = 0;
	int ans = 0;
	for(int i=0; i<M-2; i++) {
		if(s[i]=='I' && s[i+1]=='O' && s[i+2]=='I') {
			cnt++;
			if(cnt>=N) ans++;
			
			i++;
		}
		else cnt = 0;
	}
	
	cout << ans;	
	
	return 0;
}
