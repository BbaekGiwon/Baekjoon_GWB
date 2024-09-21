#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cnt=0;
int result=-1;

void merge(int *input, int left, int right, int size, int kk) {
	int l, r, k, i;
	int mid = (left + right) /2;
	l=left;
	r=mid+1;
	k=left;
	int temp[size];
	
	while(l<=mid &&r<=right) {
		temp[k++] = input[l] <= input[r] ? input[l++] : input[r++];
		cnt++;
		if(cnt==kk) result=temp[k-1];
	}
	
	if(l>mid) {
		for(i=r; i<=right; i++) {
			temp[k++] = input[i];
			cnt++;
			if(cnt==kk) result=temp[k-1];
		}
	}
	else {
		for(i=l; i<=mid; i++) {
			temp[k++] = input[i];
			cnt++;
			if(cnt==kk) result=temp[k-1];
		}
	}
	
	for(i=left; i<=right; i++) {
		input[i] = temp[i];
	}
}

void mergesort(int *input, int left, int right, int size, int k) {
	if(left==right) return;
	int mid=(left+right) /2;
	mergesort(input, left, mid, size, k);
	mergesort(input, mid+1, right, size, k);
	merge(input, left, right, size, k);
}

int main(void) {
	int n, k;
	cin >> n >> k;
	int input[n];
	
	for(int i=0; i<n; i++) {
		cin >> input[i];
	}
	
	mergesort(input, 0, n-1, n, k);
	
	cout << result;
}
