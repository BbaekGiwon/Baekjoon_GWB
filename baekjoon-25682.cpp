#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m, k, min_paint=99999999;
	cin >> n >> m >> k;
	int b_first[n+1][m+1]={0,}, w_first[n+1][m+1]={0,};
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			b_first[i][j]=0;
			w_first[i][j]=0;
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			char temp;
			cin >> temp;
			if(temp=='B') {
				if((i+j)%2==0) {
					b_first[i][j]=b_first[i-1][j]+b_first[i][j-1]-b_first[i-1][j-1];
					w_first[i][j]=w_first[i-1][j]+w_first[i][j-1]-w_first[i-1][j-1]+1;
				}
				else {
					b_first[i][j]=b_first[i-1][j]+b_first[i][j-1]-b_first[i-1][j-1]+1;
					w_first[i][j]=w_first[i-1][j]+w_first[i][j-1]-w_first[i-1][j-1];
				}
			}
			else {
				if((i+j)%2==0) {
					b_first[i][j]=b_first[i-1][j]+b_first[i][j-1]-b_first[i-1][j-1]+1;
					w_first[i][j]=w_first[i-1][j]+w_first[i][j-1]-w_first[i-1][j-1];
				}
				else {
					b_first[i][j]=b_first[i-1][j]+b_first[i][j-1]-b_first[i-1][j-1];
					w_first[i][j]=w_first[i-1][j]+w_first[i][j-1]-w_first[i-1][j-1]+1;
				}
			}
		}
	}
	

	
	for(int i=k; i<=n; i++) {
		for(int j=k; j<=m; j++) {
			int temp=min(b_first[i][j]-b_first[i-k][j]-b_first[i][j-k]+b_first[i-k][j-k], w_first[i][j]-w_first[i-k][j]-w_first[i][j-k]+w_first[i-k][j-k]);
			min_paint=min(min_paint, temp);
		}
	}
	
	cout << min_paint;
	
	return 0;
}
