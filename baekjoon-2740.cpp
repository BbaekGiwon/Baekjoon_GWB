#include <iostream>

using namespace std;

int main(void) {
	int n , m, k;
	cin >> n >> m;
	int a[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> m >> k;
	int b[m][k];
	for(int i=0; i<m; i++) {
		for(int j=0; j<k; j++) {
			cin >> b[i][j];
		}
	}
	
	int c[n][k]={0,};
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<k; j++) {
			c[i][j]=0;
			for(int x=0; x<m; x++) {
				c[i][j] += a[i][x]*b[x][j];
			}
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	
	return 0;
}
