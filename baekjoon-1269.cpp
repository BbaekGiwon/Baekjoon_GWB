#include <iostream>
#include <map>

using namespace std;

int main(void) {
	map<int,int> mm;
	int n, m, cnt=0;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		mm[temp]++;
	}
	
	for(int i=0; i<m; i++) {
		int temp;
		cin >> temp;
		if(mm[temp]!=0) cnt++;
	}
	
	cout << n+m-(2*cnt);
	
	return 0;
}
