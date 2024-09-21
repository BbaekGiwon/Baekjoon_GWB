#include <iostream>

using namespace std;

int main(void) {
	int eun[8], flag=-1;
	for(int i=0; i<8; i++) {
		cin >> eun[i];
	}
	
	if(eun[0]<eun[1]) flag=1;
	
	for(int i=1; i<7; i++) {
		if(flag==1) {
			if(eun[i]>eun[i+1]) {
				flag=0;
				break;
			}
		}
		else {
			if(eun[i]<eun[i+1]) {
				flag=0;
				break;
			}
		}
	}
	
	if(flag==1) cout << "ascending";
	else if(flag==-1) cout << "descending";
	else cout << "mixed";
	
	
	
	
	return 0;
}
