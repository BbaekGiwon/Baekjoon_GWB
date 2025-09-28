#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	if(a+b+c==180) {
		if(a!=b && b!=c && c!=a) {
			cout << "Scalene";
		}
		else {
			if(a==b && b==c && c==a) {
				cout << "Equilateral";
			}
			else {
				cout << "Isosceles";
			}
		}
	}
	else{
		cout << "Error";
	}
	
	
	return 0;
}
