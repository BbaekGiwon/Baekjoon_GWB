#include <iostream>
#include <algorithm>

using namespace std;

int k, n;
long long max_lan=0;
long long lan[10000]={0,};

long long count_lan(long long length) {
	int cnt=0;
	for(int i=0; i<k; i++) {
		cnt += lan[i]/length;
	}
	
	return cnt;
}

long long binary_search(long long left, long long right) {
	if(left>right) return max_lan;
	long long pivot=(left+right)/2;
	
//	cout << "pivot : " << pivot << "\n";

	if (count_lan(pivot)<n){
		return binary_search(left, pivot-1);
	}
	else {
		if(count_lan(pivot)>=n) {
			max_lan=max(max_lan,pivot);
		}
		return binary_search(pivot+1, right);
	}
}

	
int main(void) {
	cin >> k >> n;
	for(int i=0; i<k; i++) {
		cin >> lan[i];
	}
	
	sort(lan, lan+k);
	
	cout << binary_search(1, lan[k-1]);
	
	
	
	return 0;
}
