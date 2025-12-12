#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	
	// N = 1
	long long end_0 = 0;
	long long end_1 = 1;
	
	// N = 2~
	for(int i=2; i<=N; i++) {
		long long next_end_0 = end_0 + end_1;
		long long next_end_1 = end_0;
		end_0 = next_end_0;
		end_1 = next_end_1;
	}
	
	cout << end_0 + end_1;
	
	return 0;
}
