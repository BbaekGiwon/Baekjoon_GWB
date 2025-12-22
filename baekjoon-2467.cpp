#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	vector<long long> num(N);
	for(int i=0; i<N; i++) cin >> num[i];
	sort(num.begin(), num.end());
	
	int l = 0;
	int r = N-1;
	int ans_l, ans_r;
	long long ans_val = (1LL<<62);
	while(l<r) {
		long long temp = num[l] + num[r];
		
		if(llabs(temp) < ans_val) {
			ans_val = llabs(temp);
			ans_l = l;
			ans_r = r;
		}
		
		if(temp < 0) l++; // 음의 숫자 절대값이  더 크므로 음수의 절대값을 줄이기 
		else if(temp == 0) break; // 0 이면 종료 
		else  r--;
	}
	
	cout << num[ans_l] << " " << num[ans_r];
}
