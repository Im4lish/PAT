#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=1000;

struct Mouse {
	int weight;
	int index;
	int originIndex;
	int rank;
};

int np;
int ng;

int weight[maxn];
Mouse mouse[maxn];

bool cmp(Mouse a,Mouse b) {
	return a.originIndex<b.originIndex;
}

int main() {
	cin>>np>>ng;
	for(int i=0;i<np;++i) {
		cin>>weight[i];
	}
	for(int i=0;i<np;++i) {
		int index;
		cin>>index; 
		mouse[i].index=i;
		mouse[i].originIndex=index;
		mouse[i].weight=weight[index];
	}
	
	queue<Mouse> q;
	for(int i=0;i<np;++i) {
		q.push(mouse[i]);
	}
	
	int cnt=0;
	Mouse currentMax;
	int maxWeight=-1; 
	while(!q.empty()) {
		int size=q.size();
		int group=size/ng;
		if(size%ng!=0) {
			group++;
		}
		if(size==1) {
			Mouse now = q.front();
			mouse[now.index].rank=1;
			break;
		}
		for(int i=0;i<size;++i) {
			Mouse now = q.front();
			mouse[now.index].rank=group+1;
			q.pop();
			cnt++;
			if(now.weight>maxWeight) {
				maxWeight=now.weight;
				currentMax=now;
			}
			if(cnt==ng || i == size-1) {
				cnt=0;
				maxWeight=-1;
				q.push(currentMax);
			}
		}
	}
	
	sort(mouse,mouse+np,cmp);
	
	for(int i =0;i<np;++i) {
		if(i!=0) {
			cout<<" ";
		}
		cout<<mouse[i].rank;
	}
	return 0;
} 
