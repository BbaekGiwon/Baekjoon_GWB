#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstdlib>

using namespace std;

int main(void) {
	int n, m;
	map<int,string> m_keynum;
	map<string,int> m_keystr;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		m_keynum.insert(pair<int,string>(i,str));
		m_keystr.insert(pair<string,int>(str,i));
	}
	
	for(int i=0; i<m; i++) {
		string str;
		cin >> str;
		int temp=isdigit(str[0]);
		if(temp) {
			temp=stoi(str);
			cout << m_keynum[temp] << "\n";
		}
		else {
			cout << m_keystr[str] << "\n";
		}
	}
	
	
	
	return 0;
}
