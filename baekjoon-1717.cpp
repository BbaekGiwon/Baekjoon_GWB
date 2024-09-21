#include <iostream>

using namespace std;

typedef struct set {
	int parent;
	int rank;
}set;

set arr[1000001];

int parent(int idx) {
	if(arr[idx].parent==idx) return idx;
	else return parent(arr[idx].parent);
}

void uni(int a, int b) {
	int p_a=parent(a), p_b=parent(b);
	if(p_a == p_b) return;
	
	if(arr[p_a].rank>=arr[p_b].rank) {
		arr[p_b].parent=p_a;
		if(arr[p_a].rank==arr[p_b].rank) {
			arr[p_a].rank++;
		}
	}
	else {
		arr[p_a].parent=b;
	}
	
	
}

int main(void) {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<=n; i++) {
		arr[i].parent=i;
		arr[i].rank=0;
	}
	
	for(int i=0; i<m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if(cmd==1) {
			if(parent(a)==parent(b)) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			uni(a,b);
		}
	}	
	return 0;
}
