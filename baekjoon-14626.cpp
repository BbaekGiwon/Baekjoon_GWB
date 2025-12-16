#include <iostream>

using namespace std;

int main(void) {
	int sum = 0;
	int star_weight;
	for(int i=0; i<13; i++) {
		int weight = i%2==0 ? 1 : 3;
		
		char temp;
		cin >> temp;
		if(temp == '*') {
			star_weight = weight;
			continue;
		}
		
		sum += weight * (temp-48);
	}
	
	sum = (10 - (sum%10)) % 10;
	
	while(sum%star_weight!=0) {
		sum += 10;
	}
	
	cout << sum/star_weight;
	
	return 0;
}
