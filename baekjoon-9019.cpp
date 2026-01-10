#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;	
	cin >> T;
	
	string ans;
	
	for(int i=0; i<T; i++) {
		int input, result;
		queue<pair<int, string>> q;
		vector<bool> visited(10000, false);		
		
		cin >> input >> result;
		
		q.push({input, ""});
		visited[input] = true;
		
		while(!q.empty()) {
			int cur = q.front().first;
			string cur_s = q.front().second;
			q.pop();
			
			int D = (2*cur) % 10000;
			int S = cur==0 ? 9999 : cur-1;
			int L = (cur%1000) * 10 + cur/1000;
			int R = (cur%10) * 1000 + cur/10;
			
			if(!visited[D]) {
				if(D == result) {
					ans = cur_s + 'D';
					break;
				}
				visited[D] = true;
				q.push({D, cur_s+'D'});
			}
			
			if(!visited[S]) {
				if(S == result) {
					ans = cur_s + 'S';
					break;
				}
				visited[S] = true;
				q.push({S, cur_s+'S'});
			}
			
			if(!visited[L]) {
				if(L == result) {
					ans = cur_s + 'L';
					break;
				}
				visited[L] = true;
				q.push({L, cur_s+'L'});
			}
			
			if(!visited[R]) {
				if(R == result) {
					ans = cur_s + 'R';
					break;
				}
				visited[R] = true;
				q.push({R, cur_s+'R'});
			}
			
			
				
		}
		
		
		cout << ans << "\n";
	}
	
	
	
	return 0;
}
