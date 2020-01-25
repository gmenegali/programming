#include <iostream>
#include <vector>
#include <string>

using namespace std;

class node{
public:
  char value;
  node **children;
  int num_children;

  node(){
    children = (node **) malloc(sizeof(node *));
    num_children = 0;
  }

  void add_value(char c){
    value = c;
  }

  char get_value(){
    return value;
  }

  void add_child(node *n){
    num_children++;
    children = (node **) realloc(children, num_children * sizeof(node *));
    children[num_children-1] = n;
  }

  int get_num_children(){
    return num_children;
  }

  node ** get_children(){
    return children;
  }

  void print_children(){
    cout << "Node: " << value << ", children: "; 
    for(int i=0; i<num_children; i++){
      cout << children[i]->value << ", ";
    }  
    cout << endl;
  }

};

class trie{
public:
  node *root;

  trie(){
    root = (node *) malloc(sizeof(node));
    root->add_value('/');
  }

  node *has_child_n(node *n, char target){
    node *result = NULL;
    int num_child = n->get_num_children();
    node **child = n->get_children();

    for(int i=0; i<num_child; i++){
      if(child[i]->get_value() == target){
        result = child[i];
        return result;
      }
    }

    return result;
  }

  void print_words(node *n, string result){
    // n->print_children();
    char node_value = n->get_value();
    if(node_value != '/' and node_value != '*') result.push_back(node_value);
    if(node_value == '*') cout << result << endl;

    int num_child = n->get_num_children();
    node **child = n->get_children();

    for(int i=0; i<num_child; i++){
      print_words(child[i], result);
    }    
  }

  void print_words_with_prefix(node *n, string prefix, string result){
    char node_value = n->get_value();
    
    if((int) prefix.size() > 0){
      node *result_child = has_child_n(n, prefix[0]);
      if(result_child == NULL) return;
      else{
        n = result_child;
        if((int) prefix.size() != 1) result.push_back(prefix[0]);
        prefix.erase(prefix.begin());
        print_words_with_prefix(n, prefix, result);
      }  
    }
    else{
      if(node_value != '/' and node_value != '*') result.push_back(node_value);
      if(node_value == '*') cout << result << endl;

      int num_child = n->get_num_children();
      node **child = n->get_children();

      for(int i=0; i<num_child; i++){
        print_words_with_prefix(child[i], prefix, result);
      }  
    }
        
  }

  void add_word(string s){
    node *current_node = root;
    node *new_nodes = (node *) malloc(s.size() * sizeof(node));

    for(int i=0; i<(int)s.size(); i++) new_nodes[i].add_value(s[i]);
    for(int i=0; i<(int)s.size(); i++){
      node *result = has_child_n(current_node, s[i]);
      if(result == NULL){
        current_node->add_child(&new_nodes[i]);
        current_node = &new_nodes[i];
      }
      else current_node = result;
    }
    node *word_end = (node *) malloc(sizeof(node));
    word_end->add_value('*');
    current_node->add_child(word_end);
  }
};


int main(){
  trie t;
  t.add_word("amor");
  t.add_word("amora");
  t.add_word("anestesia");
  t.add_word("anoiteceu");
  t.add_word("adoeceu");
  t.add_word("simpatia");
  t.add_word("sim");
  t.add_word("simposio");

  t.print_words(t.root, "");
  cout << endl << endl;
  t.print_words_with_prefix(t.root, "simp", "");
  cout << endl << endl;
  t.print_words_with_prefix(t.root, "an", "");

  return 0;
}