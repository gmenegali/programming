#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node *l;
	Node *r;
	Node *father;
	Node() : l(nullptr), r(nullptr), father(nullptr) {} 
	Node(int x) : value(x), l(nullptr), r(nullptr), father(nullptr) {}
};

struct Tree{
	Node *root;
	Tree() : root(nullptr) {}
};

void add_node(Node *&n, int value){
	Node *newNode = new Node(value);

	if(n == nullptr){
		n = newNode;
	}
	else{
		if(n->value > value){
			if(n->l != nullptr){
				add_node(n->l, value);
			}
			else{
				n->l = newNode;
				n->l->father = n;
			}
		}
		else if(n->value < value){
			if(n->r != nullptr){
				add_node(n->r, value);
			}
			else{
				n->r = newNode;
				n->r->father = n;
			}
		}
	}
}

bool is_leaf(Node *&target){
	bool is_leaf = false;
	if(target->l == nullptr and target->r == nullptr){
		is_leaf = true;
	}
	return is_leaf;
}

Node * biggest_leaf_from_left(Node *&target){
	if(is_leaf(target)){
		return target;
	}

	if(target->r != nullptr){
		return biggest_leaf_from_left(target->r);
	}

	return nullptr;
}

Node * smallest_leaf_from_right(Node *&target){
	if(is_leaf(target)){
		return target;
	}

	if(target->l != nullptr){
		return smallest_leaf_from_right(target->l);
	}

	return nullptr;
}

char father_direction(Node *&target){
	Node *parent = target->father;
	if(parent->l == target)
		return 'l';
	else if(parent->r == target)
		return 'r';
	else return '-';
}

void handle_remove(Tree &t, Node *target){
	//If is leaf -> Delete and put a fix the father pointer
	//Else choose between the smallest from the right or the biggest from the left
	Node *parent = target->father;
	cout << &(parent->r) << endl;
	cout << &target << endl;


	char parent_direction = father_direction(target);

	if(is_leaf(target)){
		if(parent_direction == 'l'){
			parent->l = nullptr;
		}
		else{
			parent->r = nullptr;
		}
		delete target;
		return;
	} 
	else{
		Node *sucessor;
		if(target->l != nullptr){
			sucessor = biggest_leaf_from_left(target->l);
		}
		else if(target->r != nullptr){
			sucessor = smallest_leaf_from_right(target->r);
		}

		if(sucessor != target->l){
			sucessor->l = target->l;
			sucessor->l->father = sucessor;
		}
		if(sucessor != target->r){
			sucessor->r = target->r;
			sucessor->r->father = sucessor;
		}
		if(father_direction(sucessor) == 'r'){
			parent->r = nullptr;
		}
		else if(father_direction(sucessor) == 'l'){
			parent->l = nullptr;
		}
		sucessor->father = parent;

		// // Node *parent = target->father;
		// cout << target << endl;
		// cout << parent << endl;
		// cout << parent->r << endl;
		// cout << sucessor << endl << endl;
		// parent->r = sucessor;
		// cout << target << endl;
		// cout << parent << endl;
		// cout << parent->r << endl;
		// cout << sucessor << endl;
		
		// if(father_direction(target) == 'r'){
		// 	parent->r = sucessor;
		// }
		// else if(father_direction(target) == 'l'){
		// 	parent->l = sucessor;
		// }
		delete target;
	}

}

void remove_node(Tree &t, Node *&root, int value){
	if(root->value == value){
		return handle_remove(t, root);
	}

	if(root->value > value){
		return remove_node(t, root->l, value);
	}

	if(root->value < value){
		return remove_node(t, root->r, value);
	}
}

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
	add_node(t.root, 25);
	add_node(t.root, 14);
	add_node(t.root, 36);
	add_node(t.root, 3);
	add_node(t.root, 17);
	add_node(t.root, 20);
	add_node(t.root, 19);
	add_node(t.root, 21);
	remove_node(t, t.root, 20);
	// print_tree(t.root);

	// clear_tree(t.root);

	return 0;
}