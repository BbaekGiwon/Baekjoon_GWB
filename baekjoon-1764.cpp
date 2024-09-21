#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	map<string,int> mm;
	vector<string> v;
	int n, m, cnt=0;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		mm[str]++;
	}
	
	for(int i=0; i<m; i++) {
		string str;
		cin >> str;
		if(++mm[str]>1) {
			cnt++;
			v.push_back(str);
		}
	}
	
	sort(v.begin(),v.end());
	cout << cnt << "\n";
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << "\n";
	}
	
	
	return 0;
}
