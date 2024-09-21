#include <iostream>
#define MAX 1000001

using namespace std;

int arr[MAX]={0,};

int main(void) {
	for(int i=2; i<MAX; i++) {
		arr[i]=i;
	}
	for(int i=2; i<MAX; i++) {
		if(arr[i]==0) continue;
		for(int j=2; i*j<MAX; j++) {
			arr[i*j]=0;
		}
	}
	
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int n, sum=0;
		cin >> n;
		for(int j=2; j<=n/2; j++) {
			if(arr[j]!=0&&arr[n-j]!=0) sum++;
		}
		cout << sum << endl;
	}
	
	
	
	
	return 0;
}
