#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int n;

struct Node {
	int left;
	int right;
};

Node node[20];

bool exist[20];

int cnt=0;
int lastnode=0;

void bfs(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(now != -1) {
			lastnode = now;
			cnt++;
		} else {
			if(cnt != n) {
				cout<<"NO "<<root; 
			} else {
				cout<<"YES "<<lastnode;
			}
			return;
		}
		q.push(node[now].left);

		q.push(node[now].right);
	}
}


int main() {
	fill(exist,exist+20,false);
	scanf("%d",&n);
	getchar();
	char a[4];
	char b[4];
	for(int i=0;i<n;++i) {
		scanf("%s %s",a,b);
		if(a[0] == '-') {
			node[i].left=-1;
		} else {
			int temp;
			sscanf(a,"%d",&temp);
			node[i].left=temp;
			exist[temp]=true;
		}
		if(b[0] == '-') {
			node[i].right=-1;
		} else {
			int temp;
			sscanf(b,"%d",&temp);
			node[i].right=temp;
			exist[temp]=true;
		} 
	}
	
	int root = -1;
	for(int i=0;i<n;++i) {
		if(exist[i] == false) {
			root = i;
			break;
		}
	}
	bfs(root);
	return 0;
}

