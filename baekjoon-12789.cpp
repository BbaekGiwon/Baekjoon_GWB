#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int n, cnt=1;
	cin >> n;
	stack<int> line, space;
	for(int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		space.push(temp);
	}
	
	for(int i=0; i<n; i++) {
		line.push(space.top());
		space.pop();
	}
	
	while(1) {
		//if(!line.empty()) cout << line.top() << "\n";
		if(!line.empty()) {
			if(line.top()==cnt) {
				cnt++;
				line.pop();
			}
			else {
				if(!space.empty() && space.top()==cnt) {
					cnt++;
					space.pop();
				}
				else {
					space.push(line.top());
					line.pop();
				}
			}
		}
		else {
			if(space.empty()) {
				cout << "Nice";
				return 0;
			}
			else {
				if(cnt==space.top()) {
					cnt++;
					space.pop();
				}
				else {
					cout << "Sad";
					return 0;
				}
			}
		}
	}
	
	
	
	
	return 0;
}
