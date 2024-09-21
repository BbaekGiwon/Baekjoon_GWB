#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int flag=1;
	string str;
	cin >> str;
	
	for(int i=0; i<str.size()/2; i++) {
		if(str[i]!=str[str.size()-1-i]) {
			flag=0;
			break;
		}
	}
	
	cout << flag;
	
	
	return 0;
}
