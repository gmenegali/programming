#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void permutation_calc(vector<int> &current, vector<int> &left, vector<vector<int>> &result){
	if(left.size() == 0){
		result.push_back(current);
		return;
	}

	for(int i=0; i<(int) left.size(); i++){
		current.push_back(left[i]);
		int value = left[i];
		left.erase(left.begin()+i);
		permutation_calc(current, left, result);
		current.pop_back();
		left.insert(left.begin()+i, value);
	}

}

vector<vector<int>> permutation(vector<int> &v){
	vector<vector<int>> result;
	vector<int> current;
	vector<int> left = v;

	permutation_calc(current, left, result);

	return result;
}


int main(){

	vector<int> v= {1,2,3};
	vector<vector<int>> p = permutation(v);
	for(vector<int> vi : p){
		printVec(vi);
	}

	return 0;
}