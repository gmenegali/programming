#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
	ll t, a, b, x, y, n,takeFromA, takeFromB;
	
	cin >> t;
	while(t){
		cin >> a >> b >> x >> y >> n;
		if(a > b){
			swap(a,b);
			swap(x,y);
		}

		int takeFromA = min(n, a-x);
		int takeFromB = min(n, b-y);
		int potentialA = a - takeFromA;
		int potentialB = b - takeFromB;

		if(potentialA > potentialB){
			takeFromB = min(n, b-y);
			b -= takeFromB;
			n -= takeFromB;
			
			takeFromA = min(n, a-x);
			a -= takeFromA;
			n -= takeFromA;
				
		}
		else {
			takeFromA = min(n, a-x);
			a -= takeFromA;
			n -= takeFromA;
			
			takeFromB = min(n, b-y);
			b -= takeFromB;
			n -= takeFromB;	
		}
		

		cout << a * b  << endl;
		t--;
	}


	return 0;
}