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

		int digit, sum = 0;
		larger = 0, result = 0;
		for(int i=digits-1; i>=0; i--){
			digit = ((n % (ll)pow(10,i+1))/((ll)pow(10,i)));
			sum += digit;

			if(sum < s){
				larger = (larger*10)+digit;
			}


			if(sum > s){
				break;
			}
		}

		if(sum <= s){
			result = 0;
		}

		else{
			if(count_digits(larger) >= count_digits(n)){
				result = (ll) pow(10, count_digits(n)) - n;
			}
			else{
				larger++;
				while(larger < n){
					larger *= 10;
				}
				result = larger-n;
			}
		}

		cout << result << endl;
		t--;
	}


	return 0;
}