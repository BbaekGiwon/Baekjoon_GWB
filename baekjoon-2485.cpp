#include <iostream>
#include <vector>
#include <algorithm>
//씨발 죽어도 유클리드 호제법 안쓴다 

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, div=1;
	cin >> n;
	int tree[n];
	vector<int> gap;
	for(int i=0; i<n; i++) {
		cin >> tree[i];
		if(i!=0) {
			if(find(gap.begin(), gap.end(), tree[i]-tree[i-1])==gap.end()) {
				gap.push_back(tree[i]-tree[i-1]);
			}
		}
	}
	sort(gap.begin(),gap.end());
	
	for(int i=gap[0]; i>=2; i--) {
		int j;
		for(j=0; j<gap.size(); j++) {
			if(gap[j]%i!=0) {
				break;
			}
		}
		if(j==gap.size()) {
			div=i;
			break;
		}
	}
		
	cout << (tree[n-1]-tree[0])/div-n+1;
		
	return 0;
}
