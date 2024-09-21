#include <iostream>
#include <map>

using namespace std;

int main(void) {
	int n, m;
	map<string, bool> mop;
	string str;
	int res = 0;
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> str;
		mop.insert(pair<string,bool>(str, true));
	}
	
	for(int i=0; i<m; i++) {
		cin >> str;
		if(mop[str]==true) res++;
	}
	cout << res;
}
