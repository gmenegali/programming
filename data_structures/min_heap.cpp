#include<iostream>
#include <queue>

using namespace std;

class node{
public:
  int value;
  node *left = NULL;
  node *right = NULL;
};

class heap{
public:
  node *root = NULL;
};

void printHeap(node *n){
  cout << (*n).value << endl;
  if((*n).left != NULL) printHeap((*n).left);
  if((*n).right != NULL) printHeap((*n).right);
}

node *next_insertion_node(node *root){
  node *temp = NULL;
  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    temp = q.front(); 
    q.pop();

    if( (*temp).left != NULL ) q.push( (*temp).left);
    else return temp;

    if( (*temp).right != NULL ) q.push( (*temp).right);
    else return temp;
  }
  return temp;
}

int delete_swap_target(node *root){
  node *temp = NULL;
  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    temp = q.front();
    q.pop();

    if( (*temp).left != NULL ) q.push( (*temp).left);
    if( (*temp).right != NULL ) q.push( (*temp).right);
    if((int) q.size() == 1) return (*(q.front())).value; 
  }
  return -1;
}

void fix_min(node *n){
  if((*n).left == NULL and (*n).right == NULL) return;
  else{
    if((*n).left != NULL) fix_min((*n).left);
    if((*n).right != NULL) fix_min((*n).right);

    if((*n).left != NULL and ((*n).left)->value < (*n).value){
      int cache = ((*n).left)->value;
      ((*n).left)->value = (*n).value;
      (*n).value = cache;
    }

    if((*n).right != NULL and ((*n).right)->value < (*n).value){
      int cache = ((*n).right)->value;
      ((*n).right)->value = (*n).value;
      (*n).value = cache;
    }
  }
}

void heap_insert(heap *h, int value){
  node *n = (node *) malloc(sizeof(node));
  (*n).value = value;

  if((*h).root == NULL) (*h).root = n;
  else{
    node *target = next_insertion_node( (*h).root );
    if((*target).left == NULL) (*target).left = n;
    else (*target).right = n;
    fix_min((*h).root);
  }
}

void delete_element(node *root, int target){
  if((*root).left != NULL) delete_element((*root).left, target);
  if((*root).right != NULL) delete_element((*root).right, target);
  if( (*root).right != NULL and ( ((*root).right)->value == target ) ){
    (*root).right = NULL;
    return;
  }
  if( (*root).left != NULL and ( ((*root).left)->value == target ) ){
    (*root).left = NULL;
    return;
  }
}

#define min_root_value(x, y) ((*x).value <= (*y).value) ? x:y
void fix_max(node *root){

  if((*root).left != NULL and (*root).right != NULL){
    node *node_min = min_root_value((*root).left, (*root).right);
    if( (*root).value > (*node_min).value){
      int cache = (*root).value;
      (*root).value = (*node_min).value;
      (*node_min).value = cache;
      fix_max(node_min);
    }
  }
  else if((*root).left != NULL and (*root).right == NULL){
    if( (*root).value > ((*root).left)->value){
      int cache = (*root).value;
      (*root).value = ((*root).left)->value;
      ((*root).left)->value = cache;
      fix_max((*root).left);
    } 
  }
  else if((*root).left == NULL and (*root).right != NULL){
    if( (*root).value > ((*root).right)->value){
      int cache = (*root).value;
      (*root).value = ((*root).right)->value;
      ((*root).right)->value = cache;
      fix_max((*root).right);
    }
  }
  else return;
}

int heap_pop(heap *h){
  int last_value = delete_swap_target((*h).root);
  delete_element((*h).root, last_value);
  ((*h).root)->value = last_value;
  fix_max((*h).root);

  return 0;
}


int main(){
  heap h;

  heap_insert(&h, 5);
  heap_insert(&h, 10);
  heap_insert(&h, 7);
  heap_insert(&h, 11);
  heap_insert(&h, 12);
  heap_insert(&h, 13);
  heap_insert(&h, 14);
  heap_insert(&h, 15);
  heap_insert(&h, 16);

  // node *test = delete_swap_target(h.root);
  // cout << (*test).value << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  printHeap(h.root);
  heap_pop(&h);
  cout << endl;
  // cout << (*(h.root)).value << endl;
  return 0;
}