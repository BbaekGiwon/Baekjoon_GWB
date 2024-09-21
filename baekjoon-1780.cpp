#include <iostream>

using namespace std;

int minus_one=0, zero=0, one=0, pap[2187][2187];

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
		int x_mid1=(x1*2+x2)/3, y_mid1=(y1*2+y2)/3;
		int x_mid2=(x1+x2*2)/3, y_mid2=(y1+y2*2)/3;
		
		cutpap(x1, y1, x_mid1, y_mid1);
		cutpap(x_mid1+1, y1, x_mid2, y_mid1);
		cutpap(x_mid2+1, y1, x2, y_mid1);
		
		cutpap(x1, y_mid1+1, x_mid1, y_mid2);
		cutpap(x_mid1+1, y_mid1+1, x_mid2, y_mid2);
		cutpap(x_mid2+1, y_mid1+1, x2, y_mid2);
		
		cutpap(x1, y_mid2+1, x_mid1, y2);
		cutpap(x_mid1+1, y_mid2+1, x_mid2, y2);
		cutpap(x_mid2+1, y_mid2+1, x2, y2);
		return;
	}
	else {
		if(color_flag==-1) minus_one++;
		else if(color_flag==0) zero++;
		else one++;
		return;
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
	
	cout << minus_one << "\n" << zero << "\n" << one;
	
	return 0;
}
