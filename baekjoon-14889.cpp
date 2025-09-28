#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> stat(n, vector<int>(n));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> stat[i][j];
		}
	}
	
	int min_diff=1e9;
	vector<bool> select(n, false);
    // N/2개를 true로 설정
    fill(select.begin(), select.begin() + n/2, true);

    do {
        vector<int> group1, group2;
        for (int i = 0; i < n; i++) {
            if (select[i]) group1.push_back(i);
            else group2.push_back(i);
        }

        int sum_1=0, sum_2=0;
        for(int i : group1){
        	for(int j: group1) {
        		sum_1 += stat[i][j];
			}
		}
		for(int i : group2){
        	for(int j: group2) {
        		sum_2 += stat[i][j];
			}
		}
		
		min_diff = min(min_diff, abs(sum_1 -sum_2));
        

    } while (prev_permutation(select.begin(), select.end()));
	
	cout << min_diff<<endl;
	
	return 0;
}


