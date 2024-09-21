#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main(void) {
	set<string> mem;
	int n, cnt=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		string input;
		cin >> input;
		if("ENTER"==input) {
			mem.clear();
		}
		else if(mem.insert(input).second) {
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
