#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}


vector<int> sieve(int limit){
	vector<int> table(limit+1, 0);
	vector<int> result;

	for(int i = 2; i < limit+1; i++){
		if(table[i] == 0){
			result.push_back(i);
			for(int j = i; j < limit+1; j += i){
				table[j] = 1;
			}
		}
	}

	return result;
}

vector<int> factorialToPrimes(int n, int m, vector<int> &primes){
		int num_primes = (int) primes.size();
		vector<int> result(num_primes, 0);

		while(n > m){
			int number = n;
			while(number != 1){
				for(int i=0; i < num_primes; i++){
					while(number % primes[i] == 0){
						number /= primes[i];
						result[i]++;
					}

					if(number == 1) break;
				}
			}
			n--;
		}

		return result;
	}

class Solution{
public:
	int calc(int n, int k, int p){
		int result = 1;
		int biggest = max(k,p);
		int smallest = min(k,p);

		vector<int> primes = sieve(n);
		vector<int> multiples = factorialToPrimes(n, biggest, primes);
		vector<int> divisors = factorialToPrimes(smallest, 1, primes);
		for(int i=0; i < (int) primes.size(); i++){
			result *= pow(primes[i], (multiples[i] - divisors[i]));
		}
		
		return result;
	}

	int uniquePaths(int m, int n) {
		int steps = m + n - 2;
		
		return calc(steps, m-1, n-1);
	}

};

int main(){
	Solution s;
	cout << s.uniquePaths(7,3) << endl;
	return 0;
}




