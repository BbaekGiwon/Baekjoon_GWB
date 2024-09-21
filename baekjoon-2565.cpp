#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp_1[501]={0,};
int dp_2[501]={0,};

//bool cmp()

int main(void) {
	int n, result=0;
	vector<pair<int,int> > v;
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		int a,b;
		cin >> a >> b;
		v.push_back(pair<int,int>(a,b));
	}
	
	sort(v.begin(),v.end());
	
	for(int i=1; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(v[i].first>v[j].first&&v[i].second>v[j].second) {
				dp_1[i]=max(dp_1[i], dp_1[j]+1);
			}
		}
	}
	/*
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			if(input[i][0]>input[j][0]&&input[i][1]>input[j][1]) {
				dp_2[i]=max(dp_2[i], dp_2[j]+1);
			}
		}
	}
	
	for(int i=1; i<=n; i++) dp_1[i]+=dp_2[i]; */
	for(int i=1; i<=n; i++) result = max(result, dp_1[i]);
	
	cout << n-result-1;
}
