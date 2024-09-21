#include <iostream>

using namespace std;

int white=0, blue=0, pap[128][128];

void cutpap(int x1, int y1, int x2, int y2) {
	int color_flag=pap[x1][y1], cut_flag=0;
	for(int i=x1; i<=x2; i++) {
		for(int j=y1; j<=y2; j++) {
			if(color_flag!=pap[i][j]) {
				cut_flag=1;
				break;
			}
		}
		if(cut_flag==1) break;
	}
	
	if(cut_flag==1) {
		int x_mid=(x1+x2)/2, y_mid=(y1+y2)/2;
		cutpap(x1, y1, x_mid, y_mid);
		cutpap(x_mid+1, y1, x2, y_mid);
		cutpap(x1, y_mid+1, x_mid, y2);
		cutpap(x_mid+1, y_mid+1, x2, y2);
		return;
	}
	else {
		if(color_flag==0) white++;
		else blue++;
		return ;
	}
}

int main(void) {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> pap[i][j];
		}
	}
	
	cutpap(0, 0, n-1, n-1);
	
	cout << white << "\n" << blue;
	
	return 0;
}
