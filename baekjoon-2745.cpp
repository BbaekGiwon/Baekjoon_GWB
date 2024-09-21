#include <iostream>
#include <string>

using namespace std;

int main(void){
	string n;
	int b, j=1, result=0;
	
	cin >> n >> b;
	
	for(int i=n.length()-1; i>=0; i--) {
		if(n[i]>='A' && n[i]<='Z') {
			result+=(n[i]-'A'+10)*j;
		}
		else{
			result+=(n[i]-'0')*j;
		}
		j*=b;
	}
	
	cout << result;
	
	
	
	return 0;
}
