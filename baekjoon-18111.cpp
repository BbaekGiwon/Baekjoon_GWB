#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m, b, f_min=500, f_max=-1, t_min=2147483647, floor;
	cin >> n >> m >> b;
	int ground[n][m];
	
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> ground[i][j];
			f_min=min(f_min, ground[i][j]);
			f_max=max(f_max, ground[i][j]);
		}
	}
	
	for(int i=f_min; i<=f_max; i++) {
		int t_sum=0, block=b;
		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++) {
				if(ground[j][k]>i) {
					t_sum+=2*(ground[j][k]-i);
					block+=(ground[j][k]-i);
				}
				else if(ground[j][k]<i) {
					block-=(i-ground[j][k]);
					t_sum+=(i-ground[j][k]);
				}
			}
		}
		if(block<0) break;
		
		if(t_min >= t_sum) {
			t_min = t_sum;
			floor=i;
		}
	}
	
	cout << t_min << " " << floor;
	
	
	
	return 0;
}
