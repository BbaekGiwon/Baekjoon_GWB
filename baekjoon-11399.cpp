#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	vector<int> v;
	cin >> n;
	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(),v.end());
	
	int sum=0, j=n;
	for(int i=0; i<n; i++) {
		sum+=v[i]*j--;
	}	
	
	cout << sum;
	
	return 0;
}
