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
	int t, n, n_copy;
	string s;
	unordered_map<char, int> memo;
	bool no;

	cin >> t;
	while(t){
		no = false;
		cin >> n;
		n_copy = n;
		while(n){
			cin >> s;
			for(int i=0; i<(int)s.size(); i++){
				if(memo.find(s[i]) == memo.end()){
					memo.emplace(s[i], 1);
				} else {
					memo[s[i]] += 1;
				}
			}
			n--;
		}
		for(auto i=memo.begin(); i!=memo.end(); i++){
			if(i->second % n_copy != 0){
				cout << "NO" << endl;
				no = true;
				break;
			}
		}
		if(!no){
			cout << "YES" << endl;
		}
		memo.clear();
		t--;
	}


	return 0;
}