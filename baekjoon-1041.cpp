#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main(void) {
	long long n, sum=numeric_limits<long long>::max(), dice[6], three[3], cnt=0;
	cin >> n;
	for(int i=0; i<6; i++) cin >> dice[i];
	
	
	if(n==1) {
		sort(dice, dice+6);
		
		for(int i=0; i<5; i++) {
			sum += dice[i];
		}
	}
	else {
		for(int i=0; i<4; i++) {
			for(int j=i+1; j<5; j++) {
				for(int k=j+1; k<6; k++) {
					
					long long temp=0;
					if(i+j!=5 && j+k!=5 && k+i!=5) {
						cnt++;
						three[0]=dice[i];
						three[1]=dice[j];
						three[2]=dice[k];
						sort(three, three+3);
						
						temp+=((5*n-4)*(n-1)+n)*three[0];
						temp+=8*(n-1)*three[1];	
						temp+=4*three[2];
						sum=min(sum,temp);
					}
				}
			}
		}
	
	}
	
	
	
	cout << cnt << endl << sum;
	
	
	
	
	
	
	return 0;
}
