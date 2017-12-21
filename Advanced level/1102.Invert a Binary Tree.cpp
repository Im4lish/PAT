#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;


vector<int> in;
vector<int> level;

struct Node {
	int left;
	int right;
};

Node node[10];
bool exist[10];

void levelorder(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(node[now].left != -1) {
			q.push(node[now].left);
		}
		if(node[now].right != -1) {
			q.push(node[now].right);
		}
		level.push_back(now);
	}
}

void inorder(int root) {
	if(node[root].left == -1 && node[root].right == -1) {
		in.push_back(root);
		return;
	}
	if(node[root].left != -1) {
		inorder(node[root].left);
	}
	in.push_back(root);
	if(node[root].right != -1) {
		inorder(node[root].right);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	getchar();
	fill(exist,exist+10,false);
	for(int i=0;i<n;++i) {
		char left;
		char right;
		scanf("%c %c",&right,&left);
		getchar();
		if(left == '-') {
			node[i].left=-1;
		} else {
			node[i].left=left-'0';
			exist[left-'0']=true;
		}
		if(right == '-') {
			node[i].right=-1;
		} else {
			node[i].right=right-'0';
			exist[right-'0']=true;
		}
	}
	
	int root =-1;
	for(int i=0;i<n;++i) {
		if(exist[i] == false) {
			root=i;
			break;
		}
	}
	levelorder(root);
	inorder(root);
	for(int i=0;i<n;++i) {
		if(i == n-1) {
			printf("%d\n",level[i]);
		} else {
			printf("%d ",level[i]);
		}
	}
	for(int i=0;i<n;++i) {
		if(i == n-1) {
			printf("%d\n",in[i]);
		} else {
			printf("%d ",in[i]);
		}
	}
	return 0;
} 
