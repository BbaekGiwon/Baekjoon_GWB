#include <iostream>

using namespace std;

int n, cnt=0;
int chess[15]={0,};

int possible(int row) {
	for(int i=0; i<row; i++) {
		if(chess[i]==chess[row] || row-i==abs(chess[i]-chess[row])) {
			return 0;
		}
	}
	return 1;
}

void nqueen(int row) {
	if(n==row) {
		cnt++;
		return;
	}
	
	for(int i=0; i<n; i++) {
		chess[row]=i;
		if(possible(row)) {
			nqueen(row+1);
		}
	}
}

int main(void) {
	cin >> n;
	
	nqueen(0);
	
	cout << cnt;	
	
	return 0;
}
