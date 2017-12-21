#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=110;

int n;
int m;
int w;


struct Node {
	int id;
	int weight;
	vector<int> child;
};

Node tree[maxn];

bool cmp(int a,int b) {
	return tree[a].weight > tree[b].weight;
}


vector<int> path(maxn);

void dfs(int index,int layer,int sum) {
	if(sum > w) {
		return;
	}
	if(sum == w) {
		if(tree[index].child.size() != 0) {
			return;
		} else {
			for(int i=0;i<layer;++i) {
				if(i==layer-1) {
					cout<<tree[path[i]].weight<<endl;
				} else {
					cout<<tree[path[i]].weight<<" ";
				}
				
			}
		}
	}
	for(int i=0;i<tree[index].child.size();++i) {
		int child = tree[index].child[i];
		path[layer]=child;
		dfs(child,layer+1,sum+tree[child].weight);
	}
}

int main() {
	cin>>n>>m>>w;
	for(int i=0;i<n;++i) {
		int weight;
		cin>>weight;
		tree[i].id=i;
		tree[i].weight=weight;
	}
	
	for(int i=0;i<m;++i) {
		int id;
		int num;
		cin>>id>>num;
		for(int j=0;j<num;++j) {
			int child;
			cin>>child;
			tree[id].child.push_back(child);	
		}
		sort(tree[id].child.begin(),tree[id].child.end(),cmp);
	}
	path[0]=0;
	dfs(0,1,tree[0].weight);
	
	
	return 0;
} 
