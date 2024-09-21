#include <iostream>

using namespace std;

typedef struct {
	string sub;
	float hak;
	string score;
}jolup;
int main(void) {
	float res=0, sut=0;
	
	for(int i=0; i<20; i++) {
		jolup input;
		float temp;
		cin >> input.sub >> input.hak >> input.score;
		if(input.score[0]=='P') continue;
		
		sut+=input.hak;
		
		if(input.score[0]=='F') continue;
		
		temp=69-input.score[0];
		
		if(input.score[1]=='+') temp+=0.5;
		
		res+=input.hak*temp;
		
	}
	
	cout << res/sut;
	
	
	
	return 0;
}
