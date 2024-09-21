#include <iostream>

using namespace std;

int dp[21][21][21]={0,};

int w(int a, int b, int c);

int main(void) {
	int a, b, c, result;
	
	while(1) {
		cin >> a >> b >> c;
		if(a==-1&&b==-1&&c==-1) return 0;
		cout <<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c) <<endl;
	}
}

int w(int a, int b, int c) {
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) return dp[20][20][20] = w(20,20,20);
	else if(dp[a][b][c]!=0) return dp[a][b][c];
	else if(a<b&&b<c) return dp[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else return dp[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}
