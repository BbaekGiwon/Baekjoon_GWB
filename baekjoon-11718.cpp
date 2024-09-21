#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int i=0;
	while(i<100) {
		string str;
		getline(cin, str);
		cout << str << "\n";
		i++;
	}
	
	
	
	return 0;
}
