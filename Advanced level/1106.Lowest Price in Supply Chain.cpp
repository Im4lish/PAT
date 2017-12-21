#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn=100100;

int n;
double price;
double rate;

struct Node {
	vector<int> child;
};

Node node[maxn];

int mindeepth=999999;
int cnt=0;

void dfs(int root,int deepth) {
	if(deepth > mindeepth) {
		return;
	}
	
	if(node[root].child.size() == 0) {
		if(deepth < mindeepth) {
			mindeepth=deepth;
			cnt=1;
		} else if(deepth == mindeepth){
			cnt++;
		}	
	}
	
	for(int i=0;i<node[root].child.size();++i) {
		dfs(node[root].child[i],deepth+1);
	} 
}

int main() {
	cin>>n>>price>>rate;
	for(int i=0;i<n;++i) {
		int k;
		cin>>k;
		for(int j=0;j<k;++j) {
			int temp;
			cin>>temp;
			node[i].child.push_back(temp);
		}
	}
	dfs(0,0);
	printf("%.4f %d",price*pow(1+rate/100,mindeepth),cnt);
}
