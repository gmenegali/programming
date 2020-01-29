#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class node{
public:
  int name;
  int value;
  vector<node *> children;

  node(){}

  node(int n, int v){
    name = n;
    value = v;
  }

  void add_child(node *child){
    children.push_back(child);
  }

  vector<node *> get_children(){return children;}
  int get_value(){return value;}
  int get_name(){return name;}

  void print_node(){
    cout << name << "(" << value << "), ";
  }

  void print_children(){
    for(int i=0; i<(int) children.size(); i++) children[i]->print_node();
    cout << endl;
  }

};

bool has_visited(vector<node> &visited, node target){
  for(int i=0; i< (int) visited.size(); i++){
    if(visited[i].get_name() == target.get_name()) return true;
  }
  return false;
}

void print_nodes(vector<node> nodes){
  for(int i=0; i<(int) nodes.size(); i++) nodes[i].print_node();
    cout << endl;
  }

class graph{
public:
  vector<node> nodes;

  void add_node(int v){
    int name = (int) nodes.size();
    node n(name, v);
    nodes.push_back(n);
  }

  void print_graph(){
    for(int i=0; i<(int) nodes.size(); i++){
      cout << i << ": ";
      nodes[i].print_children();
    }
  }

  void add_edge_directed(int name_origin, int name_dest){
    nodes[name_origin].add_child(&nodes[name_dest]);
  }

  void add_edge_undirected(int name_origin, int name_dest){
    nodes[name_origin].add_child(&nodes[name_dest]);    
    nodes[name_dest].add_child(&nodes[name_origin]);
  }

  vector<node> get_nodes_dfs_operator(int root_name, vector<node> &visited){
    vector<node> result;
    vector<node> more_results;

    node root = nodes[root_name];
    result.push_back(root);
    // root.print_node();
    visited.push_back(root);

    vector<node *> root_children = root.get_children();
    for(int i=0; i<(int) root_children.size(); i++){
      if(has_visited(visited, *(root_children[i])) == false){
        more_results = get_nodes_dfs_operator(root_children[i]->get_name(), visited);
        result.insert(result.end(), more_results.begin(), more_results.end());
      }
    } 
    return result;
  }

  vector<node> get_nodes_dfs(int root_name){
    vector<node> visited;
    return get_nodes_dfs_operator(root_name, visited);
  }

  vector<node> get_nodes_bfs(int root_name){
    vector<node> visited;
    vector<node> result;

    node root = nodes[root_name];
    queue<node> q;
    q.push(root);

    while(!q.empty()){
      node current_node = q.front();
      
      if(has_visited(visited, current_node) == false){
        visited.push_back(current_node); 
        // (q.front()).print_node();
      }
      q.pop();

      vector<node *> node_children = current_node.get_children();
      for(int i=0; i<(int) node_children.size(); i++){
        if(has_visited(visited, *(node_children[i])) == false){
          q.push(*(node_children[i]));
        }
      }
    }
    return visited;
  }

  vector<node> get_path_simple(int origin_name, int dest_name){
    vector<node> result;
    vector<node> visited;
    vector<int> parents((int) nodes.size(), -1);

    node origin = nodes[origin_name];
    queue<node> q;
    q.push(origin);
    // result.push_back(origin);

    while(!q.empty()){
      node current_node = q.front();
      
      if(has_visited(visited, current_node) == false){
        visited.push_back(current_node); 
        // (q.front()).print_node();
      }
      q.pop();

      vector<node *> node_children = current_node.get_children();
      for(int i=0; i<(int) node_children.size(); i++){
        if(has_visited(visited, *(node_children[i])) == false){
          if(parents[ node_children[i]->get_name() ] == -1) parents[node_children[i]->get_name()] = current_node.get_name();
          q.push(*(node_children[i]));
        }
      }
    }
    parents[origin_name] = origin_name;

    if(parents[dest_name] == -1) return result;

    int current_name = dest_name;
    stack<node> s;
    while(parents[current_name] != current_name){
      s.push(nodes[current_name]);
      current_name = parents[current_name];
    }

    s.push(origin);
    while(!s.empty()){
      result.push_back(s.top());
      s.pop();
    }

    return result;
  }
  
  
int main(){
  graph g;
  g.add_node(0);
  g.add_node(1);
  g.add_node(2);
  g.add_node(3);
  g.add_node(4);
  g.add_node(5);
  g.add_edge_directed(0,1);
  g.add_edge_directed(0,4);
  g.add_edge_directed(0,5);
  g.add_edge_directed(1,3);
  g.add_edge_directed(1,4);
  g.add_edge_directed(2,1);
  g.add_edge_directed(3,2);
  g.add_edge_directed(3,4);

  g.print_graph();
  vector<node> visited;
  visited = g.get_path(0,2);

  // node a(0,0);
  // node b(1,1);
  // node c(2,2);
  // node d(3,3);

  // a.add_child(&b);
  // a.add_child(&c);
  // a.add_child(&d);

  // vector<node *> children = a.get_children();

  // cout << "B adress: " << &b << endl;
  // cout << "C adress: " << &c << endl;
  // cout << "D adress: " << &d << endl;

  for(int i=0; i<(int) visited.size(); i++) visited[i].print_node();
  cout << endl;


  return 0;
}