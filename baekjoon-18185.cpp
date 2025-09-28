#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> v(n+2);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	v[n]=0;
	v[n+1]=0;
	
	int idx=0;
	int result=0;
	while(idx < n) {
		if(v[idx]==0) {
			idx++;
		}
		else if(v[idx] > v[idx+1]) {
			result += (v[idx] - v[idx+1]) * 3;
			v[idx] = v[idx+1];
		}
		else if(v[idx] > v[idx+2]) {
			result += (v[idx] - v[idx+2]) * 5;
			v[idx+1] -= (v[idx] - v[idx+2]);
			v[idx] = v[idx+2];
		}
		else {
			result += v[idx] * 7;
			v[idx+1] -= v[idx];
			v[idx+2] -= v[idx];
			v[idx] = 0;
		}
		//cout << "idx: " << idx << ", result: " << result << "\n";
	}
	
	
	cout << result;
	
	
	
	
	return 0;
}
