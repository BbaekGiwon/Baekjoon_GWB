#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	int n,cnt=1;
	set<string> rainbow;
	rainbow.insert("ChongChong");
	cin >> n;
	for(int i=0; i<n; i++) {
		string a, b;
		cin >> a >> b;
		if(find(rainbow.begin(), rainbow.end(), a)!=rainbow.end()) {
			if(rainbow.insert(b).second==true) {
				cnt++;
			}
		}
		else if(find(rainbow.begin(), rainbow.end(), b)!=rainbow.end()) {
			if(rainbow.insert(a).second==true) {
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	
	return 0;
}
