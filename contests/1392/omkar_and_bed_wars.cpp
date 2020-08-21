#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int solve(int n, string s){
	int result=0, counter = 1, b = 1, e = n;
	char prev = s[0];

	if(prev == s[n-1]){
		//begin
		for(b = 1; b < n; b++){
			if(s[b] == prev){
				counter++;
			} 
			else break;
		}

		//end
		if(b != n){
			for(e = n-1; e > 0; e--){
				if(s[e] == prev){
					counter++;
				}
				else break;
			}
			e++;
		} else {
			return 1 + (counter-1)/3;
		}
		// cout << s << endl;
		// cout << "counter: " << counter << endl;
		result += counter/3;
		counter = 1;		
	}

	for(int i = b; i < e; i++){
		if(s[i] == prev){
			counter++;
		} else{
			counter = 1;
			prev = s[i];
		}

		if(i != n-1 and counter > 1 and s[i] != s[i+1]){
			result += counter/3;
		}

		if(i == n-1 and counter > 1){
			result += counter/3;
		}
	}

	return result;
}


int main(){
	int t, n;
	string s;

	cin >> t;
	while(t){
		cin >> n >> s;
		cout << solve(n, s) << endl;
		t--;
	}

	return 0;
}