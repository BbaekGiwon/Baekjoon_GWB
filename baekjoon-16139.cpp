#include <iostream>
#include <string>

using namespace std;

int main(void) {ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	string input;
	int n;
	
	cin >> input >> n;
	int prefix_sum[input.size()][26]={0,};
	for(int i=0; i<input.size(); i++) {
		if(i!=0) {
			for(int j=0; j<26; j++) {
				prefix_sum[i][j]=prefix_sum[i-1][j];
			}
		}
		
		prefix_sum[i][input[i]-'a']++;
	}
	for(int i=0; i<n; i++) {
		char alph;
		int st, en;
		cin >> alph >> st >> en;
		if(st==0) {
			cout << prefix_sum[en][alph-97] << "\n";
			continue;
		}
		cout << prefix_sum[en][alph-97] - prefix_sum[st-1][alph-97] << "\n";
	}
	
	return 0;
}
