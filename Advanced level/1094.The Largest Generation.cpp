#include<iostream>  
#include<vector>
#include<queue>

using namespace std;


struct Node {
	int num=0;
	vector<int> child;
	int layer=0;
}; 

int maxNum=0;
int numlevel=0;
int maxLevel=0;

const int maxn=100;

Node node[maxn]; 
bool visit[maxn]={false};
int n;
int m;
int num[maxn];

void BFS(int s) {
	queue<Node> q;
	node[s].layer=1;
	q.push(node[s]);
	visit[s]={false};
	while(!q.empty()) {
		Node now=q.front();
		q.pop();
		for(int i=0;i<now.num;++i) {
			int nowChild=now.child[i];
			if(visit[nowChild] == false) {
				node[nowChild].layer=now.layer+1;
				if(node[nowChild].layer>numlevel) {
					numlevel=node[nowChild].layer;
				}
				q.push(node[nowChild]);
			}
		}
	}
	
}

int main() {
	fill(num,num+maxn,0);
	cin>>n>>m;
	for(int i=0;i<m;++i) {
		int id;
		int num;
		cin>>id>>num;
		node[id].num=num;
		for(int i=0;i<num;++i) {
			int c;
			cin>>c;
			node[id].child.push_back(c);
		}
	}
	BFS(1);
	for(int i=1;i<=n;++i) {
		num[node[i].layer]++;
	}
	for(int i=1;i<numlevel;++i) {
		if(num[i]>maxNum) {
			maxNum=num[i];
			maxLevel=i;
		}
	}
	cout<<maxNum<<" "<<maxLevel;
	return 0;
}
