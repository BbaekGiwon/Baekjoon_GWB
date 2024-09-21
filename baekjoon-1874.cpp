#include <iostream>
#include <vector>

using namespace std;

char dp[1000000]={'\0',};
bool a=1;
int k=0, j=1;
vector<int> v;

void arraypos(int input) {
	if(v.back()==input) {
		v.pop_back();
		dp[k++]='-';
	}
	else {
		if(v.back()>input) {
			a=0;
		}
		else {
			v.push_back(j++);
			dp[k++]='+';
			return arraypos(input);
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	int input[n];
	for(int i=0; i<n; i++) {
		cin >> input[i];
		
	}
	
	v.push_back(0);
	
	for(int i=0; i<n; i++) {
		arraypos(input[i]);
		if(a==0) {
			cout << "NO\n";
			return 0;
		}
	}

	for(int i=0; dp[i]!='\0'; i++) {
		cout << dp[i] << "\n";
	}
	
	
	
	return 0;
}
