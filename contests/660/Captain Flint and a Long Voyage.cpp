#include <iostream>
#include <cstdio>

using namespace std;

void maxR(int n){
	int count_8;
	if(n % 4 == 0){
		count_8 = (n / 4);
	} else {
		count_8 = (n / 4) + 1;
	}
	for(int i=0; i < n-count_8; i++)
		cout << "9";
	for(int i=0; i < count_8; i++)
		cout << "8";
	cout << endl;
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
		cin >> n;
		maxR(n);
	}

	return 0;    
}