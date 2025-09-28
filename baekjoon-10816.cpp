#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	unordered_map<int,int> mm;
	cin >> n;
	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		mm[temp]++;
	}
	
	cin >> m;
	for(int i=0; i<m; i++) {
		int temp;
		cin >> temp;
		cout << mm[temp] << " ";
	}
	
	
	return 0;
}
