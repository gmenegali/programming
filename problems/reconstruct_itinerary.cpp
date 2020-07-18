#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  unordered_map<string, vector<string>> graph;
  vector<string> result_path;
  int target_size;

  void print_vec(vector<string> &v){
    for(int i=0; i<(int)v.size(); i++){
      cout << v[i] << " ";
    }
    cout << endl;
  }

  void print_list(vector<vector<string>> &v){
    for(int i=0; i<(int)v.size(); i++){
      for(int j=0; j<(int)v[i].size(); j++){
        cout << v[i][j] << " ";
      }
      cout << endl;
    }
  }

  void print_graph(unordered_map<string, vector<string>> graph){
    for(auto it = graph.begin(); it != graph.end(); it++){
      cout << it->first << " - ";
      vector<string> v = it->second;
      print_vec(v);
    }
  }

  bool backtracking(vector<string> result){
    if((int) result.size() == target_size){
      result_path = result;
      print_vec(result_path);
      return true;
    }

    int result_len = (int) result.size();
    string current_node = result[result_len-1];
    
    for(int i=(int) graph[current_node].size()-1; i>=0; i--){
      string next_node = graph[current_node][i];
      result.push_back(next_node);
      graph[current_node].erase(graph[current_node].begin() + i);

      if(backtracking(result)){
        return true;
      } else {
        result.pop_back();
        graph[current_node].insert(graph[current_node].begin() + i, next_node);
      }
    }
    return false;
  }


  vector<string> findItinerary(vector<vector<string>>& tickets) {
    target_size = (int) tickets.size() + 1;
    
    for(int i=0; i<(int)tickets.size(); i++){
      graph[tickets[i][0]].push_back(tickets[i][1]);
    }

    for(auto it = graph.begin(); it != graph.end(); it++){
      sort(it->second.begin(), it->second.end(), greater<string>()); 
    }

    backtracking({"JFK"});

    return result_path;
  }
};

int main(){
  vector<vector<string>> tickets = {
    {"MUC", "LHR"},
    {"JFK", "MUC"},
    {"SFO", "MUC"},
    {"LHR", "SJC"},
    {"MUC", "SFO"},
    {"LHR", "ABC"},
    {"ABC", "LHR"},
  };

  Solution s;
  s.findItinerary(tickets);

  return 0;
}