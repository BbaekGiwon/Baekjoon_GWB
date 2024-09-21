#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	long dis[n-1], oil[n];
	
	for(int i=0; i<n-1; i++) {
		cin >> dis[i];
	}
	
	for(int i=0; i<n; i++) {
		cin >> oil[i];
	}
	
	long res=0, temp=oil[0], dissum=dis[0];
	for(int i=1; i<n-1; i++) {
		if(temp<oil[i]) {
			dissum+=dis[i];
		}
		else {
			res+=temp*dissum;
			temp=oil[i];
			dissum=dis[i];
		}
	}
	res+=temp*dissum;
	
	cout << res;	
	
	return 0;
}
