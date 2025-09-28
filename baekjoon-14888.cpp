#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> num;
vector<int> oper;

int n;
int max_num = numeric_limits<int>::min();
int min_num = numeric_limits<int>::max();

void brute(int depth, int sum) {
	if(depth==n) {
		max_num = max(max_num, sum);
		min_num = min(min_num, sum);
		return;
	}
	
	if(oper[0]>0) {
		oper[0]--;
		brute(depth+1, sum+num[depth]);
		oper[0]++;
	}
	if(oper[1]>0) {
		oper[1]--;
		brute(depth+1, sum-num[depth]);
		oper[1]++;
	}
	if(oper[2]>0) {
		oper[2]--;
		brute(depth+1, sum*num[depth]);
		oper[2]++;
	}
	if(oper[3]>0) {
		oper[3]--;
		brute(depth+1, sum/num[depth]);
		oper[3]++;
	}
	
	return;
}

int main(void) {
	cin >> n;
	
	int temp;
	for(int i=0; i<n; i++) {
		cin >> temp;
		num.push_back(temp);
	}
	for(int i=0; i<4; i++) {
		cin >> temp;
		oper.push_back(temp);
	}
	
	brute(1,num[0]);
	
	cout << max_num << "\n" << min_num;
	
	
	
	return 0;
}
