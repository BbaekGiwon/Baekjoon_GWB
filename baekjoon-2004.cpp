#include <iostream>

using namespace std;

int main(void) {
	int n, m, j=5, k=2, result_5=0, result_2=0;
	
	cin >> n >> m;
	
	for(int i=1; i<=13; i++) {
		result_5 = result_5 + (n/j - (n-m)/j - m/j);
		j*=5;
	}
	
	for(int i=1; i<=30; i++) {
		result_2 = result_2 + n/k - (n-m)/k - m/k;
		k*=2;
	}
	
	if(result_5>result_2) result_5=result_2;
	
	cout << result_5 << endl;	
}
