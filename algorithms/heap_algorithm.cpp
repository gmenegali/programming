#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void heap_algorithm(int n, vector<int> &A){
	cout << "N: " << n << " --- ";
	printVec(A);
	
	if(n == 1){
		printVec(A);
		return;
	}

	for(int i=0; i<n; i++){
		heap_algorithm(n-1, A);
		if(n % 2 == 0){
			swap(A[i], A[n-1]);
		} else{
			swap(A[0], A[n-1]);
		}
		// heap_algorithm(n-1, A);
	}
}

int main(){

	vector<int> v = {1,2,3};
	heap_algorithm((int) v.size(), v);


	return 0;
}