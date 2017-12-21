#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn=1000;

struct Node {
	int level=0;
	vector<int> child; 
};

int maxLevel=1;
int level[maxn];

Node tree[maxn];

void bfs(Node s) {
	queue<Node> q;
	q.push(s);
	while(!q.empty()) {
		Node cur = q.front();
		q.pop();
		if(cur.child.size() == 0) {
			level[cur.level]++;
		}
		for(int i=0;i<cur.child.size();++i) {
			Node temp = tree[cur.child[i]];
			temp.level=cur.level+1;
			maxLevel=temp.level;
			q.push(temp);
		} 
	}
}

int main() {
	fill(level,level+maxn,0);
	int m;
	int n;
	cin>>m>>n;
	for(int i=1;i<=n;++i) {
		int id;
		int cnt;
		cin>>id>>cnt;
		for(int j=0;j<cnt;++j) {
			int num;
			cin>>num;
			tree[id].child.push_back(num);
		}
	}
	tree[1].level=1;
	bfs(tree[1]);
	cout<<level[1];
	for(int i=2;i<=maxLevel;++i) {
		cout<<" "<<level[i];
	}
	return 0;
}
