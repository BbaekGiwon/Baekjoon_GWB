#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n;
	deque<int> dq;
	
	cin >> n;
	
	for(int i=0; i<n; i++) {
		int command;
		cin >> command;
		if(command==1){
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if(command==2){
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if(command==5){
			cout << dq.size() << "\n";
		}
		else if(command==6){
			if(dq.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else {
			if(dq.empty()) cout << -1 << "\n";
			else if(command==3){
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else if(command==4){
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else if(command==7){
				cout << dq.front() << "\n";
			}
			else if(command==8){
				cout << dq.back() << "\n";
			}
		}
	}
	return 0;
}
