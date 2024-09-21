#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	map<string,int> mm;
	string str;
	cin >> str;
	
	for(int i=0; i<str.size(); i++) {
		for(int j=1; j<=str.size()-i; j++) {
			string temp=str.substr(i,j);
			mm[temp]++;
		}
	}
	
	cout << mm.size();
	
	return 0;
}
