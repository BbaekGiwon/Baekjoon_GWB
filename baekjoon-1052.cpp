#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	
	int buy = 0;
	while(__builtin_popcountll(N) > K) {
		int t = (N & -N);
		N += t;
		buy += t;
	}
	
	cout << buy;
	
	return 0;
}
