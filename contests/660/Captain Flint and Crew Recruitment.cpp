#include <iostream>
#include <cstdio>

using namespace std;

void sum4(int n){
	if(n > 30){
		cout << "YES" << endl;
		if(n == 36 or n == 40 or n == 44){
			cout << "6 10 15 " << n-31 << endl;
			return;
		}
		cout << "6 10 14 " << n-30 << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main(){
	int t, n;

	cin >> t;
	while(t--){
		cin >> n;
		sum4(n);
	}

	return 0;    
}