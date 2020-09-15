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

void solution(int r, int g, int b, int w){
	int oddCounter = 0;
	if(r % 2 != 0)
		oddCounter++;
	if(g % 2 != 0)
		oddCounter++;
	if(b % 2 != 0)
		oddCounter++;
	if(w % 2 != 0)
		oddCounter++;

	if(oddCounter <= 1 or (oddCounter >= 3 and r >=1 and g >=1 and b >= 1))
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
}

int main(){
	int t, r, g, b, w;
	vector<int> testCase;
	
	cin >> t;
	while(t){
		cin >> r >> g >> b >> w;
		solution(r, g, b, w);
		t--;
	}


	return 0;
}