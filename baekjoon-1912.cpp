#include <iostream>

using namespace std;

int main(void) {
	int n;
	
	cin >> n;
	int input[n]={0,}, sum[n], result=-1000;
	for(int i=0; i<n; i++) {
		cin >> input[i];
		sum[i] = -1000;
	} 
	
	for(int i=0; i<n; i++) {
		sum[i] = max(sum[i-1]+input[i], input[i]);
		result = max(sum[i], result);
	}
	
	cout << result <<endl;
}

