#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

class node{
public:
  int key;
  int value;

  node *next;
  node *prev;

  node(){
    this->next = NULL;    
    this->prev = NULL;    
  }
  
  node(int key, int value){
    this->key = key;
    this->value = value;
    this->next = NULL;    
    this->prev = NULL;    
  }

  void set_next(node *n){
    this->next = n; 
  }

  void set_prev(node *n){
    this->prev = n; 
  }

  void print_node(){
    cout << "(" << this->key << ", " << this->value << ") ";
  }
};

class dll{
public:
  node *head;
  int n_elements;

  dll(){
    this->head = new node();
    this->n_elements = 0;
  }

  ~dll(){
    node *current = this->head;
    node *next; 
    while(current != NULL){
      next = current->next;
      delete current;
      current = next;
    }
  }

  void add(node *target){
    node *current = this->head;
    while(current->next != NULL) current = current->next;
    current->set_next(target);
    target->set_prev(current);
    this->n_elements++;
  }

  void del_target(node *target){
    if(target->next != NULL)
      (target->next)->set_prev(target->prev);
    (target->prev)->set_next(target->next);
    delete target;
    this->n_elements--;
  }

  void del_first(){
    node *target = this->head->next;
    if(target != NULL){
      if(target->next != NULL)
        (target->next)->set_prev(target->prev);
      (target->prev)->set_next(target->next);
      delete target;
      this->n_elements--;
    }
  }

  int get_first_key(){
    node *target = this->head->next;
    if(target != NULL){
      return target->key;
    }
    return -1;
  }

  void print_dll(){
    node *current = this->head->next;
    while(current != NULL){
      current->print_node();
      current = current->next;
    }    
    cout << endl;
  }
};


class LRUCache{
public:
  int max_elements;
  unordered_map<int, node*> elements;
  dll *l;

  LRUCache(int capacity) {
    max_elements = capacity;
    l = new dll();
  }

  ~LRUCache() {
    delete l;
  }
    
  int get(int key) {
    if(elements.find(key) != elements.end()){
      int value = (*(elements[key])).value;

      l->del_target(elements[key]);
      node *target = new node(key, value);
      l->add(target);
      elements[key] = target;      
      return value;
    }
    return -1;
  }
  
  void put(int key, int value) {
    if(elements.find(key) != elements.end()){
      l->del_target(elements[key]);
      node *target = new node(key, value);
      l->add(target);
      elements[key] = target;
    }
    else{
      if(l->n_elements == this->max_elements){
        int first_key = l->get_first_key();
        elements.erase(first_key);
        l->del_first();
      }
      node *target = new node(key, value);
      l->add(target);
      elements.emplace(key, target);
    }
  }

};



int main(){
  LRUCache *l = new LRUCache(2);

  l->put(2,1);
  l->put(1,1);
  l->get(2);
  l->put(4,1);
  l->get(1);
  l->get(2);
  l->put(4,1);

  // l->put(1,1);
  // l->put(2,1);
  // l->put(3,1);  
  // l->put(4,1);
  // l->put(5,1);
  // l->put(5,1);
  // l->put(5,1);
  // l->put(5,1);

  // l->put(2,1);
  // l->put(2,2);
  // l->get(2);
  // l->put(1,1);
  // l->put(4,1);
  // l->get(2);

  delete l;

  return 0;
}
