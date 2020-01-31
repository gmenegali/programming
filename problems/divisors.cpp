#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


void print_vec(vector<int> vec){
  for(int x : vec) cout << x << endl;
}

vector<int> crive(int N){
  vector<int> crive_vec(N+1, 0);
  vector<int> result;

  for(int i=2; i<(int) crive_vec.size(); i++){
    if(crive_vec[i]==0){
      result.push_back(i);
      for(int j=2; i*j<(int) crive_vec.size(); j++){
        crive_vec[i*j]= -1; 
      }
    } 
  }

  return result;
}

vector<int> prime_factorization(int N){
  vector<int> possible_primes = crive(N);
  vector<int> result;

  for(int i=0; i<(int) possible_primes.size(); i++){
    while(N % possible_primes[i] == 0){
      result.push_back(possible_primes[i]);
      N = N/possible_primes[i];
    }
    if(N==1) break;
  }
  return result;
}

vector<int> divisors_calc(vector<int> vec, vector<int> result){
  if(vec.empty()) return result;
  else{
    if(result.empty()){
      result.push_back(vec[0]);
      vec.erase(vec.begin());
      result = divisors_calc(vec, result);
    }
    else{
      vector<int> more_results;
      more_results.push_back(vec[0]);
      for(int i=0; i<(int) result.size(); i++) more_results.push_back(vec[0]*result[i]);
      for(int i=0; i<(int) more_results.size(); i++){
        bool found = false;
        for(int j=0; j<(int) result.size(); j++) if(result[j] == more_results[i]) found = true;
        if(found == false) result.push_back(more_results[i]);
      }
      vec.erase(vec.begin());
      result = divisors_calc(vec, result);

    }
  }
  return result;
}

vector<int> divisors(int N){
  vector<int> prime_factors = prime_factorization(N);
  vector<int> empty;
  vector<int> result = divisors_calc(prime_factors, empty);
  result.insert(result.begin(),1);
  return result;
}

int main(){
  vector<int> result = divisors(350);
  print_vec(result);
  // vector<int> test;
  // test.push_back(1);
  // test.push_back(2);
  // test.push_back(3);

  // vector<int> test2;
  // test2.push_back(4);
  // test2.push_back(5);
  // test2.push_back(6);

  // test.insert(test.end(), test2.begin(), test2.end());
  // print_vec(test);

  return 0;
}



