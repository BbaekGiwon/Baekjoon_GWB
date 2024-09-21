#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n;
	stack<int> s;
	cin >> n;
	for(int i=0; i<n; i++) {
		int input;
		cin >> input;
		if(input==1) {
			int x;
			cin >> x;
			s.push(x);
		}
		else if(input==2) {
			if(!s.empty()) {
				cout << s.top() << "\n";
				s.pop();
			}
			else cout << -1 <<"\n";
		}
		else if(input==3) {
			cout << s.size() <<"\n";
		}
		else if(input==4) {
			if(!s.empty()) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
		else if(input==5) {
			if(!s.empty()) cout << s.top() << "\n";
			else cout << -1 <<"\n";
		}
	}
	
	
	return 0;
}
