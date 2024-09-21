#include <iostream>

using namespace std;

int main(void) {
	int n, m=1234567891;
	long long sum=0;
	cin >> n;
	string s;
	cin >> s;
	for(int i=0; i<n; i++) {
		long long temp= (s[i]-96);
		for(int j=0; j<i; j++) {
			temp =(temp * 31) % m;
		}
		sum+=temp;
		sum%=m;
	}
	
	cout << sum;
	
	
	return 0;
}
