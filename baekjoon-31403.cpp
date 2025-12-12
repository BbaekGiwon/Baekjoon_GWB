#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int a,b,c;
	cin >> a >> b >> c;
	
	cout << a+b-c << "\n" << stoi(to_string(a)+to_string(b))-c;
	
	return 0;
}
