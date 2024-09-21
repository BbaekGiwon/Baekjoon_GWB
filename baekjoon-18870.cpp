#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	vector<int> v, s;
	cin >> n;
	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		s.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	
	for(int i=0; i<n; i++) {
		cout << upper_bound(v.begin(),v.end(),s[i])-v.begin()-1 << " ";
	}
}
