#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class trieNode {
public:
  char value;
  unordered_map<char, struct trieNode*> children;
  
  trieNode(char c){
    value = c;
  }

  void add_child(trieNode *parent, char c){
    trieNode *target = new trieNode(c);
    (parent->children).emplace(c, target);
  }
};

class Trie {
public:
  trieNode *root;

  Trie(){
    root = new trieNode('*');
  }

  ~Trie(){
    trieNode *current = root;
    for(auto child : root->children){
      
    }
    delete root;
  }

  void addWord(string word){
    trieNode *current = root;
    for(char c : word){
      if((current->children)[c]){
        current = (current->children)[c];
      } else {
        trieNode *newTrieNode = new trieNode(c);
        (current->children).emplace(c, newTrieNode);
        current = (current->children)[c];
      }
    }  
  }

  void print_children(){
  }
};

int main(){
  Trie t;
  t.addWord("gui");
  t.print_children();

  return 0;
}