#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long int

ll solution(ll p, ll f, ll cnts, ll cntw, ll s, ll w){
	ll result = 0, fs, fw, maximum = 0;
	if(s > w){ // Make the sword the lightest 
		swap(s, w);
		swap(cnts, cntw);
	}

	ll maxSwordsToP = min(cnts, p/s);
	for(ll i=0; i<=maxSwordsToP; i++){
		result = 0;
		ll wPair = min(cntw, (p-s*i)/w);
		result += i + wPair;
		
		fs = min(cnts-i, f/s);
		if(fs > 0){
			result += fs;
			fw = min(cntw-wPair, (f-s*fs)/w);
		} else {
			fw = min(cntw-wPair, f/w);
		}
		if(fw > 0)
			result += fw;

		maximum = max(maximum, result);
	}
	
	return maximum;


}


int main(){
	ll t, p, f, cnts, cntw, s, w;
	
	cin >> t;
	while(t){
		cin >> p >> f;
		cin >> cnts >> cntw;
		cin >> s >> w;
		cout << solution(p, f, cnts, cntw, s, w) << endl;
		t--;
	} 

	return 0;
}