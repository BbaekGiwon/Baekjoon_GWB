#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	vector<int> arr(3);
	
	for(int j=0; j<3; j++) {
		cin >> arr[j];
	}
	
	int prev_max[3] = {arr[0],arr[1],arr[2]};
	int prev_min[3] = {arr[0],arr[1],arr[2]};
	int cur_max[3], cur_min[3];
	
	for(int i=1; i<n; i++) {
		for(int j=0; j<3; j++) {
			cin >> arr[j];
		}
		cur_max[0] = max(prev_max[0], prev_max[1]) + arr[0];
		cur_min[0] = min(prev_min[0], prev_min[1]) + arr[0];
		
		cur_max[1] = max(max(prev_max[0], prev_max[1]), prev_max[2]) + arr[1];
		cur_min[1] = min(min(prev_min[0], prev_min[1]), prev_min[2]) + arr[1];
		
		cur_max[2] = max(prev_max[1], prev_max[2]) + arr[2];
		cur_min[2] = min(prev_min[1], prev_min[2]) + arr[2];
		
		for(int j=0; j<3; j++) {
			prev_max[j] = cur_max[j];
			prev_min[j] = cur_min[j];
		}
	}
	
	cout << max(max(prev_max[0], prev_max[1]),prev_max[2]) << "\n" << min(min(prev_min[0], prev_min[1]), prev_min[2]);
	
	
	
	
	return 0;
}
