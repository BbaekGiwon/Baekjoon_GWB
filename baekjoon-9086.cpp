#include <iostream>
#include <string>

using namespace std;

int main(void) {
	
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		cout << str.front() << str.back() << "\n";
	}
	
	return 0;
}
