#include<iostream>
#include <algorithm>
#include<queue>
using namespace std;

const int maxn=100;

struct Node {
	int value;
	int left;
	int right;
};

Node tree[maxn];

int number[maxn];

int n;

int countNode(int s) {
	if(s == -1) {
		return 0;
	}
	if(tree[s].left == -1) {
		if(tree[s].right == -1) {
			return 1;
		} else {
			return 1+countNode(tree[s].right);
		} 
	} else {
		if(tree[s].right == -1) {
			return 1+countNode(tree[s].left);
		} else {
			return 1+countNode(tree[s].right)+countNode(tree[s].left);
		} 
	}
}

void buildTree(int s,int l,int r) {
	if(l==r) {
		tree[s].value=number[l];
		return;
	}
	int left = countNode(tree[s].left);
	
	tree[s].value=number[l+left];
	
	if(tree[s].left != -1) {
		buildTree(tree[s].left,l,l+left-1);
	}
	if(tree[s].right != -1) {
		buildTree(tree[s].right,l+left+1,r);
	}
	
}

int main() {
	cin>>n;
	int l;
	int r;
	for(int i=0;i<n;++i) {
		cin>>l>>r;
		tree[i].left=l;
		tree[i].right=r;
	}
	
	for(int i=0;i<n;++i) {
		cin>>number[i];
	}
	
	sort(number,number+n);
	
	buildTree(0,0,n-1);
	queue<Node> q;
	cout<<tree[0].value;
	q.push(tree[0]);
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
		if(now.left!=-1) {
			cout<<" "<<tree[now.left].value;
			q.push(tree[now.left]);
		}
		if(now.right!=-1) {
			cout<<" "<<tree[now.right].value;
			q.push(tree[now.right]);
		}
	}
	return 0;
}
