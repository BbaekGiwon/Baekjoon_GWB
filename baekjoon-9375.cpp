#include <iostream>
#include <map>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		map<string,int> m;
		int n, res=1;
		cin >> n;
		for(int j=0; j<n; j++) {
			string te, mp;
			cin >> te >> mp;
			m[mp]++;
		}
		
		map<string,int>::iterator iter;
		for(iter=m.begin(); iter!=m.end(); iter++) {
			res*=iter->second+1;
		}
		
		cout << res-1 << "\n";
	}
	
	return 0;
}
