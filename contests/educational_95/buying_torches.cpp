#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	int t, x, y, k;
	ll aux, sticks, result = 0;
	vector<int> testCase;
	
	cin >> t;
	while(t){
		cin >> x >> y >> k;
		x--;
		result = 0;

		//how many sticks I need to transform them in coals?
		result += k;
		sticks = (k+((ll) y*k))-1;

		if(sticks % x == 0){
			result += sticks/x;
		} else{
			result += 1 + sticks/x;
		}

		

		cout << result << endl;
		t--;
	}


	return 0;
}