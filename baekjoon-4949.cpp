#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	while(1) {
		vector<int> v;
		string input;
		getline(cin, input, '\n');
		if(input==".") return 0;
		
		for(int i=0; i<input.size(); i++) {
			if(input[i]=='[') {
				v.push_back(1);
			}
			else if(input[i]==']') {
				if(v.size()==0||v.back()!=1) {
					v.push_back(1);
					break;
				}
				
				v.pop_back();
			}
			else if(input[i]=='(') {
				v.push_back(2);
			}
			else if(input[i]==')') {
				if(v.size()==0||v.back()!=2) {
					v.push_back(2);
					break;
				}
				v.pop_back();
			}
		}
		if(v.size()==0) cout << "yes\n";
		else cout << "no\n";
	}
	
	
	return 0;
}
