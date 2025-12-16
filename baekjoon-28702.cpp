#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main(void) {
	int next;
	string s[3];
	
	for(int i=0; i<3; i++) cin >> s[i];
	
	for(int i=2; i>=0; i--) {
		try {
			next = stoi(s[i]);
			
			next += (3-i);
			break;
		}
		catch (const invalid_argument& e) {
			continue;
		}
	}
	
	if(next%3 == 0) {
		if(next%5 == 0) cout << "FizzBuzz";
		else cout << "Fizz";
	}
	else {
		if(next%5 == 0) cout << "Buzz";
		else cout << next;
	}
	
	return 0;
}
