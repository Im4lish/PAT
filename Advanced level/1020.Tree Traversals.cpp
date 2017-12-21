#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn=100;

struct Node {
	int key;
	Node* left=NULL;
	Node* right=NULL;
};

vector<int> post(maxn);
vector<int> in(maxn);
vector<int> level(maxn);

Node* root = NULL;

Node* build(Node* root,int postl,int postr,int inl,int inr) {
	root = new Node;
	root->key= post[postr];
	int ink=0;
	for(int i=inl;i<=inr;++i) {
		if(in[i] == post[postr]) {
			ink=i;
			break;
		}
	}
	root->left=build(root->left,postl,postl+ink-1,inl,ink-1);
	root->right=build(root->right,postl+ink,postr-1,ink+1,inr);
	return root;
}

void levelOrder(Node* root) {
	int cnt=0;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* now = q.front();
		q.pop();
		level[cnt++] = now->key;
		if(now->left != NULL) {
			q.push(now->left);
		}
		if(now->right != NULL) {
			q.push(now->right);
		}
	}
} 


int main() {
	int n;
	cin>>n;
	post.resize(n);
	in.resize(n);
	level.resize(n);
	for(int i=0;i<n;++i) {
		cin>>post[i];
	}
	for(int i=0;i<n;++i) {
		cin>>in[i];
	}
	
	root = build(root,0,n-1,0,n-1);
	levelOrder(root);
	for(int i=0;i<n;++i) {
		if(i == 0) {
			cout<<level[i];
		} else {
			cout<<" "<<level[i];
		}
	}
	return 0;
}
