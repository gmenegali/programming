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

int solution(int x1, int y1, int z1, int x2, int y2, int z2){
	int result = 0, minimum;
	
	// 2 1 = 2
	minimum = min(z1, y2);
	z1 -= minimum;
	y2 -= minimum;
	result += 2 * minimum;
	// 2 2 = 0
	if(z1){
		minimum = min(z1, z2);
		z1 -= minimum;
		z2 -= minimum;
	}
	// 1 1 = 0
	if(y2){
		minimum = min(y1, y2);
		y1 -= minimum;
		y2 -= minimum;
	}
	

	// 1 0 = 0
	if(y1 and x2){
		minimum = min(y1, x2);
		y1 -= minimum;
		x2 -= minimum;
	}

	// 1 0 = 0
	if(x1 and z2){
		minimum = min(x1, z2);
		x1 -= minimum;
		z2 -= minimum;
	}

	// 1 2 = -2
	if(y1 and z2){
		minimum = min(y1, z2);
		result -= 2*minimum;
		y1 -= minimum;
		z2 -= minimum;
	}

	return result;
}

int main(){
	int t, x1, y1, z1, x2, y2, z2;
	
	cin >> t;
	while(t){
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		cout << solution(x1, y1, z1, x2, y2, z2) << endl;
		t--;
	}


	return 0;
}