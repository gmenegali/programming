// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *l1){
  while(l1 != NULL){
    cout << l1->val << " "; 
    l1 = l1->next;
  }
  cout << endl;
} 

ListNode *add_node(ListNode *l1, int val){
  if(l1 == NULL) l1 = new ListNode(val);
  else{
    ListNode *p = l1;
    while(p->next != NULL) p = p->next;
    p->next = new ListNode(val);
  }

  return l1;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode *result = NULL;

  while(l1 != NULL or l2 != NULL){
    if(l1 == NULL){
      while(l2 != NULL){
        result = add_node(result, l2->val);
        l2 = l2->next;
      }
    }

    else if(l2 == NULL){
      while(l1 != NULL){
        result = add_node(result, l1->val);
        l1 = l1->next;
      }
    }

    else if(l1->val < l2->val){    
      result = add_node(result, l1->val);
      l1 = l1->next;
    }

    else{
      result = add_node(result, l2->val);
      l2 = l2->next;
    }
  }

  return result;
}

int main(){
  ListNode *l1 = NULL;
  l1 = add_node(l1, 1);
  l1 = add_node(l1, 2);
  l1 = add_node(l1, 4);

  ListNode *l2 = NULL;
  l2 = add_node(l2, 1);
  l2 = add_node(l2, 3);
  l2 = add_node(l2, 4);

  ListNode *l3 = mergeTwoLists(l1, l2);
  print_list(l3);
  // add_node(&l1, 4);
  // ListNode temp = ListNode(2); 
  // l1.next = ;

  free(l1);
  free(l2);
  free(l3);
  return 0;
}