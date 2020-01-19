#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

typedef struct Double_linked_list double_linked_list;
typedef struct Node node;

struct Node{
  int key;
  int value;
  node *prev = NULL;
  node *next = NULL;
};

node *create_node(int key, int value){
  node *n = (node *) malloc(sizeof(node));
  n->value = value;
  n->key = key;
  return n;
}

//Fix ghost nodes into head and tail to not handling the NULL nodes
struct Double_linked_list{
  int nodes = 0;
  int nodes_limit;
  node *head = NULL;
  node *tail = NULL;
};

void print_dll(double_linked_list &l){
  node *current = l.head->next;
  while(current != l.tail){
    cout << "(k: " << current->key << ", v: " << current->value << ") ";
    current = current->next;
  }
  cout << endl;
}

double_linked_list *create_dll(int limit){
  double_linked_list *l = (double_linked_list *) malloc(sizeof(double_linked_list));
  l->nodes_limit = limit;

  l->head = create_node(-2,-2);
  l->tail = create_node(-1,-1);
  l->head->next = l->tail;
  l->tail->prev = l->head;

  return l;
}

void add_new_node_dll(double_linked_list &l, int key, int value, unordered_map<int,node *> &hash){
  node *n = create_node(key, value);
  hash[key] = n;
  if(l.nodes < l.nodes_limit){ //Insert the new node in the last position
    node *real_tail = l.tail->prev;

    n->next = l.tail;
    n->prev = real_tail;
    real_tail->next = n;
    l.tail->prev = n;

    l.nodes++;
  }
  else{ //Delete the first and insert the new node in the last position
    node *del_target = (l.head)->next;
    (l.head)->next = del_target->next;
    (del_target->next)->prev = l.head;
    hash.erase(del_target->key);
    free(del_target);

    ((l.tail)->prev)->next = n;
    n->prev = (l.tail)->prev;
    n->next = l.tail;
    (l.tail)->prev = n;
  }
}

void move_node_to_end(double_linked_list &l, node *target){
  node *target_prev = target->prev;
  node *target_next = target->next;

  target_prev->next = target_next;
  target_next->prev = target_prev;

  target->next = l.tail;
  target->prev = (l.tail)->prev;
  ((l.tail)->prev)->next = target; 
  l.tail->prev = target;

}


class LRUCache {
public:
  double_linked_list *l;
  unordered_map<int,node *> hash;

  int cap;

  LRUCache(int capacity) {
    l = create_dll(capacity);
    cap = capacity;
  }

  int get(int key) {
    if(hash.find(key) != hash.end()){
      node *n = hash[key];
      move_node_to_end(*l, n);
      return n->value;
    }
    else return -1;
  }

  void put(int key, int value){
    if(hash.find(key) != hash.end()){ //Found
      node *target = hash[key]; 
      move_node_to_end(*l, target);
    }
    else add_new_node_dll(*l, key, value, hash);
  }


  void print_hash(){
    unordered_map<int,node *>::iterator it = hash.begin();
    cout << "HASH: ";
    while(it != hash.end()){
      cout << "(k: " << (*it).first << " , v: " << (*it).second << "), ";
      it++;
    }
    cout << endl;
  }

  void print_lru(){
    print_dll(*l);
  }
};


int main(){
  LRUCache cache(2);
  cache.put(1, 1);
  // cache.print_lru();
  // cache.print_hash();
  
  cache.put(2, 2);
  // cache.print_lru();
  // cache.print_hash();
  
  cout << cache.get(1) << endl;       // returns 1
  // cache.print_lru();
  
  cache.put(3, 3);                    // evicts key 2
  // cache.print_lru();
  // cache.print_hash();
  
  cout << cache.get(2) << endl;       // returns -1 (not found)
  // cache.print_lru();
  
  cache.put(4, 4);                    // evicts key 1
  // cache.print_lru();
  // cache.print_hash();
  
  cout << cache.get(1) << endl;       // returns -1 (not found)
  // cache.print_lru();
  cout << cache.get(3) << endl;       // returns 3
  // cache.print_lru();
  cout << cache.get(4) << endl;       // returns 4
  // cache.print_lru();

  return 0;
}
