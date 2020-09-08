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

int count_digits(ll n){
	int count = 1;
	while(n/10 > 0){
		count++;
		n /= 10;
	}
	return count;
}

int main(){
	int t, s, digits;
	ll n, result = 0, larger=0;
	cin >> t;
	while(t){
		cin >> n >> s;
		digits = count_digits(n);

		int digit, count = 0, target=-1;
		larger = 0, result = 0;
		for(int i=digits-1; i>=0; i--){
			digit = ((n % (ll)pow(10,i+1))/((ll)pow(10,i+1)/10));
			count += digit;

			if(count < s){
				larger = (larger*10)+digit;
			}

			if(count >= s){
				target = i;
				break;
			}
		}


		if(target == -1){
			result = 0;
		}

		else{
			larger  += 1;
			result = (larger * pow(10, target+1)) - n;
		}


		cout << target << endl;
		// cout << digits << endl;
		cout << result << endl << endl;
		t--;
	}


	return 0;
}