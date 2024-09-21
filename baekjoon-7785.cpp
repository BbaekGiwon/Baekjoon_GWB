#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int main(void) {
	string enter="enter";
	map<string,int,greater<string>> mem;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string a, b;
		cin >> a >> b;
		if(b==enter) {
			if(mem.find(a)==mem.end()) {
				mem.insert(make_pair(a,1));
			}
			else {
				auto item = mem.find(a);
				item->second=1;
			}
		}
		else {
			auto item = mem.find(a);
			item->second=0;
		}
	}
	
	for(auto i=mem.begin(); i!=mem.end();i++) {
		
		if(i->second==1) {
			cout << i->first << "\n";
		}
	}
	
	
	
	return 0;
}
