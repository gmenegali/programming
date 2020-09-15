#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int> memo;

int solution(int p, int f, int cnts, int cntw, int s, int w, int np, int nf){
	int result = 0;

	string key = to_string(p) + "-" + to_string(f) + "-" + to_string(cnts) + "-" + to_string(cntw);
	if(memo.find(key) != memo.end()){
		return memo[key];
	} 

	if(((p < s and f < s) or cnts == 0) and ((p < w and f < w) or cntw == 0) ){
		return np+nf;
	}
	
	if(cnts > 0 and p >= s)
		result = max(result, solution(p-s, f, cnts-1, cntw, s, w, np+1, nf));

	if(cnts > 0 and f >= s)
		result = max(result, solution(p, f-s, cnts-1, cntw, s, w, np, nf+1));
	
	if(cntw > 0 and p >= w)
		result = max(result, solution(p-w, f, cnts, cntw-1, s, w, np+1, nf));
	
	if(cntw > 0 and f >= w)
		result = max(result, solution(p, f- w, cnts, cntw-1, s, w, np, nf+1));

	memo.emplace(key, result);
	return result;

}


int main(){
	int t, p, f, cnts, cntw, s, w, result;
	
	cin >> t;
	while(t){
		cin >> p >> f;
		cin >> cnts >> cntw;
		cin >> s >> w;
		result = solution(p, f, cnts, cntw, s, w, 0, 0);
		cout << result << endl;
		t--;
	}

	return 0;
}