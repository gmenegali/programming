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

int main(){
	int t, a, b;
	
	cin >> t;
	while(t){
		cin >> a >> b;
		if(a == b)
			cout << 0 << endl;
		else if(abs(b-a) % 10 == 0)
			cout << abs(b-a)/10 << endl;
		else
			cout << abs(b-a)/10 + 1 << endl;

		t--;
	}


	return 0;
}