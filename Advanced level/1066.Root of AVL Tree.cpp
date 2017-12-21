#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=21;

struct Node {
	int height;
	int value;
	Node* left;
	Node* right;
};

vector<int> nodes;

Node* newNode(int v) {
	Node* node = new Node();
	node->value=v;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}

int getHeight(Node* node) {
	if(node == NULL) {
		return 0;
	}
	return node->height;
}

int updateHeight(Node* node) {
	node->height=max(getHeight(node->left),getHeight(node->right))+1;
}

int getBalanceFactor(Node* node) {
	return getHeight(node->left)-getHeight(node->right);
}

void leftRotate(Node* &root) {
	Node* temp=root->right;
	root->right=temp->left;
	temp->left=root;
	updateHeight(root);
	updateHeight(temp); 
	root=temp;
}

void rightRotate(Node* &root) {
	Node* temp=root->left;
	root->left=temp->right;
	temp->right=root;
	updateHeight(root);
	updateHeight(temp); 
	root=temp;
}



void LL(Node* &root) {
	rightRotate(root);
}

void LR(Node* &root) {
	leftRotate(root->left);
	rightRotate(root);
}

void RR(Node* &root) {
	leftRotate(root);
}

void RL(Node* &root) {
	rightRotate(root->right);
	leftRotate(root);
}

void insert(Node* &root,int num) {
	if(root == NULL) {
		root = newNode(num);
		return; 
	}
	
	if(num<root->value) {
		insert(root->left,num);
		updateHeight(root);
		if(getBalanceFactor(root) == 2) {
			if(getBalanceFactor(root->left) == 1) {
				LL(root);
			} else if(getBalanceFactor(root->left) == -1) {
				LR(root);
			}
		} 
	}
	else{
		insert(root->right,num);
		updateHeight(root);
		if(getBalanceFactor(root) == -2) {
			if(getBalanceFactor(root->right) == -1) {
				RR(root);
			} else if(getBalanceFactor(root->right) == 1) {
				RL(root);
			}
		}
	}
}
	
	


int main() {
	int n;
	cin>>n;
	nodes.resize(n+1);
	
	Node* root=NULL;
	
	for(int i=0;i<n;++i) {
		int num;
		cin>>num;
		insert(root,num);
	}
	cout<<root->value;
	return 0;
}
