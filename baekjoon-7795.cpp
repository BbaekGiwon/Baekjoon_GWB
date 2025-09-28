#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		vector<int> A(a), B(b);
		for(int i=0; i<a; i++) {
			cin >> A[i];
		}
		for(int i=0; i<b; i++) {
			cin >> B[i];
		}
		
		// two pointers를 위한 정렬
		sort(A.rbegin(), A.rend());
		sort(B.rbegin(), B.rend());
		
		// result
		int res=0;
		
		// two pointers
		int pointer_a=0, pointer_b=0;
		for(int pointer_a=0; pointer_a<a; pointer_a++) {
			while(A[pointer_a] <= B[pointer_b] && pointer_b<b) pointer_b++;
			if(pointer_b==b) break;
			res += b-pointer_b;
		}
		
		cout << res << "\n";
	}
	
	
	
	return 0;
}
