#include <iostream>

using namespace std;

int main(void) {
	int n, k, i=1, cnt=0;
	cin >> n >> k;
	
	while(i<=n) {
		if(n%i==0) {
			cnt++;
			if(cnt==k) {
				cout << i;
				return 0;
			}
		}
		i++;
	}
	
	cout << "0";
	
	return 0;
}
