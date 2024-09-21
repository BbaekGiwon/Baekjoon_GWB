#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

struct word{
	string con;
	int time;
}; 

bool compare(const word& a, const word& b) {
	if(a.time==b.time) {
		if(a.con.size()==b.con.size()) {
			return a.con < b.con;
		}
		else {
			return a.con.size() > b.con.size();
		}
	}
	else {
		return a.time > b.time;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	map<string,int> dic;
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		string input;
		cin >> input;
		if(input.size()<m) {
			continue;
		}
		else {
			if(!dic.insert({input,1}).second) {
				dic[input]++;
			}
		}
	}
	
	word result[dic.size()];
	int j=0;
	for(auto i=dic.begin(); i!=dic.end(); i++) {
		result[j].con=i->first;
		result[j].time=i->second;
		j++;
	}
	
	sort(result, result+dic.size(), compare);
	
	for(int i=0; i<dic.size(); i++) {
		cout << result[i].con << "\n";
	}
	
	
	return 0;
}
