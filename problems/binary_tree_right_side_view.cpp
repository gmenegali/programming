#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
	int val;
	int nodeCounter;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}
	TreeNode(int x) : val(x), nodeCounter(1), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r){}
};

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void treeAdd(TreeNode *&r, int val){
	int position = r->nodeCounter+1;
	r->nodeCounter++;
	
	vector<char> path;
	while(position != 1){
		if(position % 2 == 0)
			path.push_back('l');
		else
			path.push_back('r');
		position /= 2;
	}
	reverse(path.begin(), path.end());

	TreeNode *aux = r;
	for(char direction : path){
		if(direction == 'l'){
			if(aux->left != nullptr){
				aux = aux->left;
			} else {
				aux->left = new TreeNode(val);
			}
		} else {
			if(aux->right != nullptr){
				aux = aux->right;
			} else {
				aux->right = new TreeNode(val);
			}
		}
	}
}

void treeClear(TreeNode *&r){
	if(r == nullptr)
		return;
	if(r->left != nullptr)
		treeClear(r->left);
	if(r->right != nullptr)
		treeClear(r->right);
	delete r;
}

void treePrintDFS(TreeNode *r){
	if(r == nullptr)
		return;
	if(r->left != nullptr)
		treePrintDFS(r->left);
	if(r->right != nullptr)
		treePrintDFS(r->right);
	cout << r->val << " ";
}

void treePrintBFS(TreeNode *r){
	if(r == nullptr)
		return;

	queue<TreeNode *> q;
	q.push(r);

	while(!q.empty()){
		if(q.front()->left != nullptr)
			q.push(q.front()->left);
		if(q.front()->right != nullptr)
			q.push(q.front()->right);
		cout << q.front()->val << " ";
		q.pop();
	}
	cout << endl;
}

class Solution{
public:
	vector<int> result;

	void rightSideViewCalc(TreeNode *root, int currentDepth){
		if(root == nullptr)
			return;
		
		if(currentDepth == (int) result.size()){
			result.push_back(root->val);
		}

		if(root->right != nullptr)
			rightSideViewCalc(root->right, currentDepth+1);
		if(root->left != nullptr)
			rightSideViewCalc(root->left, currentDepth+1);
	}

	vector<int> rightSideView(TreeNode* root) {
		rightSideViewCalc(root, 0);
		return result;
	}
};


int main(){
	TreeNode *root = new TreeNode(1);
	for(int i=2; i<20; i++)
		treeAdd(root, i);
	// treePrintDFS(root);
	// cout << endl;
	// treePrintBFS(root);

	vector<int> result;
	Solution s;
	result = s.rightSideView(root);
	printVec(result);

	treeClear(root);

	return 0;
}
