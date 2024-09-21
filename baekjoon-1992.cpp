#include <iostream>

using namespace std;

int pap[64][64];

void cutpap(int x1, int y1, int x2, int y2) {
	int color_flag=pap[y1][x1], cut_flag=0;
	for(int i=y1; i<=y2; i++) {
		for(int j=x1; j<=x2; j++) {
			if(color_flag!=pap[i][j]) {
				cut_flag=1;
				break;
			}
		}
		if(cut_flag==1) break;
	}
	
	if(cut_flag==1) {
		cout << "(";
		int x_mid=(x1+x2)/2, y_mid=(y1+y2)/2;
		cutpap(x1, y1, x_mid, y_mid);
		cutpap(x_mid+1, y1, x2, y_mid);
		cutpap(x1, y_mid+1, x_mid, y2);
		cutpap(x_mid+1, y_mid+1, x2, y2);
		cout << ")";
		return;
	}
	else {
		if(color_flag==0) cout << 0;
		else cout << 1;
		return ;
	}
}

int main(void) {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			char input;
			cin >> input;
			pap[i][j]=input-'0';
		}
	}
	
	cutpap(0, 0, n-1, n-1);
	
	return 0;
}
