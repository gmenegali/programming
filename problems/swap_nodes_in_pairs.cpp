#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  vector<ListNode *> getNodesAddresses(ListNode *&l){
		vector<ListNode *> result;
		ListNode *aux = l;
		while(aux != nullptr){
			result.push_back(aux);
			aux = aux->next;
		}
		return result;
	}

	ListNode* swapPairs(ListNode* head) {
		if(head == nullptr) return head;
		vector<ListNode *> addresses = getNodesAddresses(head);
		int numNodes = (int) addresses.size();
		ListNode *lastNode = addresses[numNodes-1];

		if(numNodes % 2 != 0){
			numNodes--;
		}

		for(int i=0; i < numNodes; i++){
			if(i%2 != 0){
				addresses[i]->next = addresses[i-1];
			} 
			else{
				if(i+3 < numNodes){
					addresses[i]->next = addresses[i+3];
				} else{
					if((int) addresses.size() % 2 != 0){
						addresses[i]->next = lastNode;
					} else {
						addresses[i]->next = nullptr;
					}
				}
			}
		}

		ListNode* result;
		if(numNodes > 1){
			result = addresses[1];
		} else {
			result = addresses[0];
		}
		return result;
	}
};

void listAddNode(ListNode *&l, int value){
	if(l == nullptr){
		l = new ListNode(value);
	} 
	else{
		ListNode *aux = l;
		while(aux->next != nullptr){
			aux = aux->next;
		}
		aux->next = new ListNode(value);
	}
}

void printList(ListNode *&l){
	ListNode *aux = l;
	while(aux != nullptr){
		cout << aux->val << " ";
		aux = aux->next;
	}
	cout << endl;
}


int main(){
	ListNode *l = nullptr;
	listAddNode(l, 1);
	listAddNode(l, 2);
	listAddNode(l, 3);
	listAddNode(l, 4);
	listAddNode(l, 5);
	// listAddNode(l, 6);

	Solution s;
	l = s.swapPairs(l);

	printList(l);

	ListNode *aux;
	while(l != nullptr){
		aux = l->next;
		delete l;
		l = aux;
	}

	return 0;
}