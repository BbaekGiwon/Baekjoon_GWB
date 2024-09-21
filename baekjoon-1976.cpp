#include <iostream>

using namespace std;

typedef struct set {
	int parent;
	int rank;
}set;

set arr[201];

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
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		arr[i].parent=i;
		arr[i].rank=0;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int cmd;
			cin >> cmd;
			if(cmd==1) {
				uni(i,j);
			}
		}
	}
	
	int pre, now, b_flag=0;
	cin >> pre;
	for(int i=0; i<m-1; i++) {
		cin >> now;
		if(parent(pre)!=parent(now)) {
			b_flag=1;
			break;
		}
		pre=now;
	}
	
	if(b_flag==1) cout << "NO";
	else cout << "YES";	
	
	return 0;
}
