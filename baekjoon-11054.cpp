#include <iostream>

using namespace std;

int dp_1[1001] = {0,};
int dp_2[1001] = {0,};

int main(void) {
	int n, result=0;
	cin >> n;
	int input[n+2]={0,};
	
	for(int i=1; i<=n; i++) {
		cin >> input[i];
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<i; j++) {
			if(input[i]>input[j]) dp_1[i] = max(dp_1[i], dp_1[j] + 1) ;
		}
	}
	
	for(int i=n; i>=1; i--) {
		for(int j=n+1; j>i; j--) {
			if(input[i]>input[j]) dp_2[i] = max(dp_2[i], dp_2[j] + 1) ;
		}
	}
	
	for(int i=1; i<=n; i++) dp_1[i]+=dp_2[i]-1;
	for(int i=1; i<=n; i++) result = max(result, dp_1[i]);
	
	cout << result << endl;
}
