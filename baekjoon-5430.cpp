#include <iostream>
#include <algorithm> 
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++) {
		int error_flag=0;
		string func;
		cin  >> func;
		
		int n;
		cin >> n;
		
		deque<int> d;
		string input;
		cin >> input;
		
		string s;
		for (int i = 0; i<input.length();i++) {

            if (isdigit(input[i])) {
                s += input[i];

            }
            else {
                if (!s.empty()) {
                    d.push_back(stoi(s));
                    s = "";
                }
            }
        }
		
		int j=0,k=0;
		bool r=false;		 
		for(j=0; j<func.size(); j++) {
			if(func[j]=='R') {
				r= !r;
			}
			else { // 'D'
				if(d.empty()) {
					cout << "error\n";
					error_flag=1;
				}
				else {
					if(r) {
						d.pop_back();
					}
					else {
						d.pop_front();
					}
					
				}
	
			}
			
			if(error_flag==1) break;
		}
		
		if(error_flag==1) {
			d.clear();
			continue;
		}
		
		if(r && !d.empty()) {
			reverse(d.begin(), d.end());
		}
		if(!d.empty()) {
			cout << "[" << *(d.begin());
			for(auto i=d.begin()+1; i!=d.end(); i++) {
				cout<< "," << *i;
			}
			cout << "]\n";
		}
		else {
			cout << "[]\n";
		}
		
		
		d.clear();
	}
	
	return 0;
}
