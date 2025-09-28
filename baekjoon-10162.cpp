#include <iostream>

using namespace std;

int main(void) {
	int t, button[3]={0,0,0};
	cin >> t;
	
	button[0]=t/300;
	t%=300;
	button[1]=t/60;
	t%=60;
	if(t%10==0) {
		button[2]=t/10;
		
		for(int i=0; i<3; i++) {
			cout << button[i] << " ";
		}
	}
	else {
		cout << "-1";
	}
	return 0;
}
