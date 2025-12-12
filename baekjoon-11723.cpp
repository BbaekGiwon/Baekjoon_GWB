#include <iostream>

using namespace std;

const string ADD = "add";
const string REMOVE= "remove";
const string CHECK = "check";
const string TOGGLE = "toggle";
const string ALL = "all";
const string EMPTY = "empty";

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n;
	bool bs[21] = {0,};
	
	cin >> n;
	for(int i=0; i<n; i++) {
		string cmd;
		int num;
		cin >> cmd;
		
		// check command
		if(cmd == ADD) {
			cin >> num;
			bs[num] = true;
		}
		else if(cmd == REMOVE) {
			cin >> num;
			bs[num] = false;
		}
		else if(cmd == CHECK) {
			cin >> num;
			if(bs[num]) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if(cmd == TOGGLE) {
			cin >> num;
			if(bs[num]) {
				bs[num] = false;
			}
			else {
				bs[num] = true;
			}
		}
		else if(cmd == ALL) {
			for(int j=1; j<=20; j++) {
				bs[j] = true;
			}
			
		}
		else if(cmd == EMPTY) {
			for(int j=1; j<=20; j++) {
				bs[j] = false;
			}
		}
	}	
	
	return 0;
}
