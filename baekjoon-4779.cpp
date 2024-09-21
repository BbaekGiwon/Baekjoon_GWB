#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void canto(char* arr, int left, int right) {
	//cout << left << " " << right << endl;
	if(left >= right) {
		return;
	}
	else {
		for(int i=left+(right-left)/3+1; i<right-(right-left)/3; i++) {
			arr[i]=' ';
		}
		canto(arr, left, left+(right-left)/3);
		canto(arr, right-(right-left)/3, right);
		return;
	}
}

int main(void) {
	int n;
	while(cin >> n) {
		int size=(int)pow(3,n);
		char *arr = new char[size];
		for(int i=0; i<size; i++) {
			arr[i]='-';
		}
		canto(arr, 0, size-1);
		for(int i=0; i<size; i++) {
			cout << arr[i];
		}
		cout << "\n";
		delete[] arr;
 	}
	
	return 0;
}
