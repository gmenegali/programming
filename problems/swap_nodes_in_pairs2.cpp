#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr){}
	ListNode(int x, ListNode *next) : val(x), next(next){}
};

void listAppend(ListNode *n, int value){
	while(n->next != nullptr){
		n = n->next;
	}
	n->next = new ListNode(value);
}

void listClear(ListNode *n){
	while(n != nullptr){
		ListNode *aux = n->next;
		delete n;
		n = aux;
	}
}

void listPrint(ListNode *n){
	while(n != nullptr){
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}

class Solution{
public:
	ListNode* swapPairs(ListNode* head) {
		if(head == nullptr or head->next == nullptr){
			return head;
		}

		ListNode *result = head->next;

		ListNode *prevSwapFirst = nullptr;
		ListNode *nextSwapFirst = nullptr;
		ListNode *currentSwapFirst = head;
		ListNode *currentSwapSecond = head->next;

		while(currentSwapFirst != nullptr){
			if(currentSwapSecond != nullptr){ //Handle odd length
				nextSwapFirst = currentSwapSecond->next;
			} else {
				nextSwapFirst = nullptr;
			}

			//changes
			if(currentSwapSecond != nullptr) //Handle odd length
				currentSwapSecond->next = currentSwapFirst;
			if(prevSwapFirst != nullptr){
				if(currentSwapSecond != nullptr){
					prevSwapFirst->next = currentSwapSecond;
				} else {	//Handle odd length
					prevSwapFirst->next = currentSwapFirst;
				}
			}

			//moving forward
			prevSwapFirst = currentSwapFirst;
			currentSwapFirst = nextSwapFirst;
			if(currentSwapFirst != nullptr) //Handle last pair
				currentSwapSecond = currentSwapFirst->next;
			else
				prevSwapFirst->next = nullptr;
		}

		return result;
	}

};


int main(){
	ListNode *l = new ListNode(1);
	listAppend(l, 2);
	listAppend(l, 3);
	listAppend(l, 4);
	listAppend(l, 5);
	// listAppend(l, 6);
	
	Solution s;
	l = s.swapPairs(l);

	listPrint(l);

	listClear(l);

	return 0;
}
