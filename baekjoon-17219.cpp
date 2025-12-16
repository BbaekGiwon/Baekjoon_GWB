#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, M;
	
	cin >> N >> M;
	
	unordered_map<string, string> map;
	map.reserve(N);
	
	for(int i=0; i<N; i++) {
		string a,b;
		cin >> a >> b;
		map[a] = b;
	}
	
	for(int i=0; i<M; i++) {
		string temp;
		cin >> temp;
		cout << map[temp] << "\n";
	}
	
	return 0;
}
