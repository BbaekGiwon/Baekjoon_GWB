#include <iostream>

using namespace std;

int stack[10001]={0,};
int last=0;

void push(int x) {
	stack[last++]=x;
//	cout << "@@@" << stack[last-1] << "@@@\n";
}

int pop(void) {
	if(last==0) return -1;
	
	int res = stack[--last];
	stack[last]=0;
	return res;
}

int empty(void) {
	if(last==0) return 1;
	else return 0;
}

int top(void) {
	if(last==0) return -1;
	return stack[last-1];
}

int main(void) {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		string input;
		cin >> input;
		if(input=="push") {
			int x;
			cin >> x;
			push(x);
		}
		else if(input=="pop") {
			cout << pop() << "\n";
		}
		else if(input=="size") {
			cout << last << "\n";
		}
		else if(input=="empty") {
			cout << empty() << "\n";
		}
		else if(input=="top") {
			cout << top() << "\n";
		}
		//cout << "###" << last << "###\n";
	}
	
	
	
	
	
	return 0;
}
