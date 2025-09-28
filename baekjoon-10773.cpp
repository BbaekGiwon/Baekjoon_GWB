#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void) {
	vector<int> v;
	int k;
	cin >> k;
	for(int i=0; i<k; i++) {
		int temp;
		cin >> temp;
		if(temp>0) {
			v.push_back(temp);
		}
		else {
			v.pop_back();
		}
	}
	
	cout << accumulate(v.begin(),v.end(),0);	
	
	return 0;
}
