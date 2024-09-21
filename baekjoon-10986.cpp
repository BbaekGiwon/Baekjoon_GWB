#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	long long input[n], namuji[m]={0,};
	
	for(int i=0; i<n; i++) {
		cin >> input[i];
		input[i]%=m;
		if(i!=0) input[i]+=input[i-1];
		input[i]%=m;
		namuji[input[i]]++; 
	}
	
	long long sum=namuji[0];
	for(int i=0; i<m; i++) {
		sum+=namuji[i]*(namuji[i]-1)/2;
	}
	

	cout << sum;	
	
	return 0;
}
