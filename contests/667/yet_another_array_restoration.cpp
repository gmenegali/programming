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

	int t, n, x, y;
	int before, middle, after;
	vector<int> divisors;
	
	cin >> t;
	while(t){
		cin >> n >> x >> y;
		int k = y - x;
		for(int i=1; i<=k; i++){
			if(k%i == 0){
				divisors.push_back(i);
			}
		}


		int minimum = INT_MAX, target_divisor=divisors[0];
		for(int i=0; i<(int)divisors.size(); i++){
			if((y-x)/divisors[i] +1 > n){
				continue;
			}

			if(x%divisors[i] == 0){
				before = max(x/divisors[i] - 1, 0);
			} else{
				before = max(x/divisors[i], 0);
			}
			middle = (y-x)/divisors[i] - 1;
			after = max(n - before - middle - 2, 0);

			if(y+after*divisors[i] < minimum){
				minimum = min(minimum, y);
				target_divisor = divisors[i];
			}
		}

		int y_copy = y;
		while(n > 0){
			while(y_copy > 0 and n > 0){
				cout << y_copy << " ";
				y_copy -= target_divisor;
				n--;
			}
			y_copy = y+target_divisor;
			while(n > 0){
				cout << y_copy << " ";
				y_copy += target_divisor;
				n--;
			}
			n--;
			cout << endl;
		}

		divisors.clear();
		t--;
	}


	return 0;
}