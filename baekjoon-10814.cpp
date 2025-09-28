#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct member {
	int age;
	string name;
	int turn;
}member;

bool compare(member a, member b) {
	if(a.age==b.age) {
		return a.turn<b.turn;
	}
	return a.age<b.age;
}

int main(void) {
	int n;
	cin >> n;
	vector<member> input;
	
	for(int i=0; i<n; i++) {
		member temp;
		cin >> temp.age >> temp.name;
		temp.turn = i;
		input.push_back(temp);
	}
	
	sort(input.begin(), input.end(), compare);
	
	for(int i=0; i<n; i++) {
		cout << input[i].age << " " << input[i].name << "\n";
	}
}
