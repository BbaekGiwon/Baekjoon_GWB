#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	vector<pair<int,int> > v;
	cin >> n;
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int,int>(b,a));
	}
	
	sort(v.begin(),v.end());
	
	
	int temp=v[0].first;
	int cnt=1;
	for(int j=1; j<n; j++) {
		if(temp<=v[j].second) {
			temp=v[j].first;
			cnt++;
		}
	}

	
	cout << cnt;
	
	
	return 0;
}
