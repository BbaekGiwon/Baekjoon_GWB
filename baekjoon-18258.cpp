#include <iostream>
#include <string>

using namespace std;

int queue[2000001]={0,};
int fr=0, ba=0;

int empty() {
	if(fr==ba) return 1;
	else return 0;
}

void push(int x) {
	queue[ba++]=x;
}

int pop() {
	if(empty()==1) return -1;
	
	int temp=queue[fr];
	queue[fr++]=0;
	return temp;
}

int size() {
	return ba-fr;
}

int front() {
	if(empty()==1) return -1;
	else return queue[fr];
}

int back() {
	if(empty()==1) return -1;
	else return queue[ba-1];
}



int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
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
			cout << size() << "\n";
		}
		else if(input=="empty") {
			cout << empty() << "\n";
		}
		else if(input=="front") {
			cout << front() << "\n";
		}
		else if(input=="back") {
			cout << back() << "\n";
		}
	}
	
	return 0;
}
