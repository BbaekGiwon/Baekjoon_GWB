#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	
	for(int i=0; i<T; i++) {
		int k;
		multiset<int> ms;
		
		cin >> k;
		
		for(int j=0; j<k; j++) {
			char c;
			int num;
			cin >> c >> num;
			
			if(c == 'I') {
				ms.insert(num);
			}
			else { // 'D'
				if(ms.empty()) continue;
				
				if(num==1) {
					ms.erase(prev(ms.end())); // MAX
				}
				else { // -1
					ms.erase(ms.begin()); // MIN
				}
			}
		}
		
		if(ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
		}
	}

	return 0;
}
