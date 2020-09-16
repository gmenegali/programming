#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *l;
	Node *r;
	Node() : l(nullptr), r(nullptr) {} 
	Node(int x) : value(x), l(nullptr), r(nullptr) {}
};

struct Tree{
	Node *root;
	Tree() : root(nullptr) {}
};

void add_nodde(Node *&n, int value){
	if(n == nullptr){
		n = new Node(value);
	}
	else{
		if(n->value >= value)
			return add_nodde(n->l, value);
		else
			return add_nodde(n->r, value);
	}
}

bool is_leaf(Node *&target){
	bool is_leaf = false;
	if(target->l == nullptr and target->r == nullptr){
		is_leaf = true;
	}
	return is_leaf;
}


// void handle_remove(Node *&target){
// 	if(is_leaf(target)){
// 		delete target;
// 	}
// 	else{
// 		Node *sucessor, *sucessor_father;

// 		//Biggest from the right
// 		if(target->r != nullptr){
// 			sucessor_father = target;
// 			sucessor = target->r;
// 			while(sucessor->l != nullptr){
// 				sucessor_father = sucessor;
// 				sucessor = sucessor->l;
// 			}
// 		}

// 		//Smallest from the left
// 		else if(target->l != nullptr){
// 			sucessor_father = target;
// 			sucessor = target->l;
// 			while(sucessor->r != nullptr){
// 				sucessor_father = sucessor;
// 				sucessor = sucessor->r;
// 			}
// 		}

// 		while(sucessor->l != nullptr or sucessor->r != nullptr){
// 			sucessor_father = sucessor;
// 			if(sucessor->r != nullptr){
// 				father_pointer = 'r';
// 				sucessor = sucessor->r;
// 			}
// 			else{
// 				father_pointer = 'l';
// 				sucessor = sucessor->l;
// 			}
// 		}

// 		target->value = sucessor->value;
// 		if(father_pointer == 'r')
// 			sucessor_father->r = nullptr;
// 		if(father_pointer == 'l')
// 			sucessor_father->l = nullptr;

// 		delete sucessor;
// 	}
// }

// void remove_nodde(Node *&root, int value){
// 	Node *target;
// 	if(root->value > value){
// 		target = root->l;
// 		if(target != nullptr){
// 			if(root->l->value != value){
// 				return remove_nodde(target, value);
// 			}
// 			if(is_leaf(target)){
// 				root->r = nullptr;
// 			}
// 			handle_remove(target);			
// 		}
// 		else
// 			cout << "Value not found." << endl;
// 	}
// 	else if(root->value < value){
// 		target = root->r;
// 		if(target != nullptr){
// 			if(root->r->value != value){
// 				return remove_nodde(target, value);
// 			}
// 			if(is_leaf(target)){
// 				root->r = nullptr;
// 			}
// 			handle_remove(target);
// 		}
// 		else
// 			cout << value << " not found. Could not be removed." << endl;

// 	}
// 	else //In case the root is the target
// 		return remove_nodde(root, value);
// }

// Node *sucessor(Node *&root){

// }

// Node *antecessor(){
	
// }

void clear_tree(Node *n){
	if(n->l != nullptr)
		clear_tree(n->l);
	if(n->r != nullptr)
		clear_tree(n->r);
	delete n;
}

void print_tree(Node *n){
	if(n->l != nullptr)
		print_tree(n->l);
	if(n->r != nullptr)
		print_tree(n->r);
	cout << n->value << endl;
}


int main(){
	Tree t;
	add_nodde(t.root, 25);
	add_nodde(t.root, 14);
	add_nodde(t.root, 36);
	add_nodde(t.root, 3);
	add_nodde(t.root, 17);
	add_nodde(t.root, 20);
	add_nodde(t.root, 19);
	add_nodde(t.root, 21);
	print_tree(t.root);
	cout << endl;
	remove_nodde(t.root, 21);
	print_tree(t.root);
	cout << endl;
	remove_nodde(t.root, 20);
	print_tree(t.root);
	cout << endl;
	remove_nodde(t.root, 14);
	print_tree(t.root);
	cout << endl;
	remove_nodde(t.root, 17);
	print_tree(t.root);
	cout << endl;
	// cout << (t.root->value) << endl;
	// delete t.root;
	// cout << t.root->value << endl;

	clear_tree(t.root);
	// delete t;

	return 0;
}