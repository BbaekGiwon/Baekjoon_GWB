#include <iostream> 

using namespace std;

int main(void) {
	int N;
	int size[6];
	int T, P;
	
	cin >> N;
	for(int i=0; i<6; i++) cin >> size[i];
	cin >> T >> P;
	
	int total_shirt=0;
	for(int i=0; i<6; i++) {
		total_shirt += (size[i] + T - 1) / T;
	}
	cout << total_shirt << "\n";
	cout << N/P << " " << N%P;
	
	return 0;
}
