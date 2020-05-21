// You are given coins of different denominations and a total amount of money amount. 
// Write a function to compute the fewest number of coins that you need to make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return -1.


#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

void print_vec(vector<int> v){
  for(int i=0; i<(int)v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

void print_map(unordered_map<int,int> m){
  for(auto it = m.begin(); it != m.end(); it++){
    cout << it->first << " " << it->second << endl;
  }
}

class Solution{
public:
  unordered_map<int,int> min_coins_table;
  
  int coinChangeCalc(vector<int> &coins, int amount){
    if(amount == 0) return 0;

    int min_coins_num = INT_MAX;
    int necessary_coins;
    for(int i=0; i < (int) coins.size(); i++){
      if(coins[i] <= amount){
        if(min_coins_table.find(amount - coins[i]) != min_coins_table.end())
          necessary_coins = min_coins_table[amount - coins[i]] + 1;
        else
          necessary_coins = coinChangeCalc(coins, amount-coins[i]) + 1;
        
        if(necessary_coins != 0) // Not possible, so -1 + 1 = 0, because you added 1 in the necessary coins
          min_coins_num = min(min_coins_num, necessary_coins);
      }
    }

    if(min_coins_num == INT_MAX){ //Not possible
      min_coins_table[amount] = -1;
      return -1;
    }

    min_coins_table[amount] = min_coins_num;
    return min_coins_num;
  }

  int coinChange(vector<int>& coins, int amount) {
    min_coins_table.clear();
    for(int i=0; i < (int) coins.size(); i++){
      min_coins_table.emplace(coins[i], 1);
    }

    return coinChangeCalc(coins, amount);
  }

};


int main(){
  vector<int> v;
  
  v.push_back(206);  
  v.push_back(280);  
  v.push_back(362);  
  v.push_back(59);  
  v.push_back(486);  
  v.push_back(27);
  v.push_back(177);
  v.push_back(437);
  v.push_back(329);
  
  Solution S;
  cout << S.coinChange(v,7621) << endl;  
  // print_map(S.min_coins_table);

  return 0;
}