#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9+7;

vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b) {
	vector<vector<long long>> result(2, vector<long long>(2, 0));
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			result[i][j] = 0;
			for(int k=0; k<2; k++) {
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	return result;
}

vector<vector<long long>> power(vector<vector<long long>> base, long long exp) {
	if(exp == 1) return base;
	vector<vector<long long>> half = power(base, exp/2);
		
	if(exp %2 == 0) return mul(half, half);
	else return mul(mul(half, half), base);
}


// n번째 피보나치 구하기
long long fibonacci(long long n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    vector<vector<long long>> base = {{1,1},{1,0}};
    vector<vector<long long>> res = power(base, n-1);
    return res[0][0]; // F(n)
}

int main(void) {
	long long n;
	cin >> n;
	
	cout << fibonacci(n);
	
	
	return 0;
}
