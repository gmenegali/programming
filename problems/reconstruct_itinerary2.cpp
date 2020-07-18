#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  unordered_map<string, vector<string>> graph;
  vector<string> result_path;

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

  bool dfs_postorder(string current){
    bool unvisited_edges;
    for(auto i: graph){
      if(i.second.size()){
        unvisited_edges = true;
        break;
      }
    }
    if(!unvisited_edges){
      result_path.push_back(current);
      return true;
    }

    vector<string> possibilities = graph[current];
    int num_possibilities = (int) possibilities.size();

    for(int i=num_possibilities-1; i >= 0; i--){
      string next = possibilities[i];
      graph[current].erase(graph[current].begin() + i);

      if(dfs_postorder(next)){
        result_path.push_back(current);
        return true;
      } else {
        graph[current].insert(graph[current].begin() + i, next);
      }
    }

    return false;
  }


  vector<string> findItinerary(vector<vector<string>>& tickets) {    
    for(int i=0; i<(int)tickets.size(); i++){
      graph[tickets[i][0]].push_back(tickets[i][1]);
    }

    for(auto it = graph.begin(); it != graph.end(); it++){
      sort(it->second.begin(), it->second.end(), greater<string>()); 
    }

    dfs_postorder("JFK");
    reverse(result_path.begin(), result_path.end());
    print_vec(result_path);

    return result_path;
  }
};

int main(){
  // vector<vector<string>> tickets = {
  //   {"MUC", "LHR"},
  //   {"JFK", "MUC"},
  //   {"SFO", "MUC"},
  //   {"LHR", "SJC"},
  //   {"MUC", "SFO"},
  //   {"LHR", "ABC"},
  //   {"ABC", "LHR"},
  // };
  vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};


  Solution s;
  vector<string> a = s.findItinerary(tickets);
  s.print_vec(a);
  return 0;
}