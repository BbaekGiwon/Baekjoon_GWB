#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparelength(string a, string b) {
	if(a.length() == b.length()) {
		return a<b;
	}
	return a.length()<b.length();
}

int main(void) {
	int n;
	cin >> n;
	vector<string> input;
	
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		if(find(input.begin(), input.end(), str)==input.end()) {
			input.push_back(str);
		}
	}
	sort(input.begin(), input.end(), comparelength);
	
	for(int i=0; i<input.size(); i++) {
		cout << input[i] << '\n';
	}
}
