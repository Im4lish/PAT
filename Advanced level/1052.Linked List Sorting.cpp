#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=999999;

struct Node {
	int address;
	int value;
	int next;
	bool flag=false;
};

bool cmp(Node a,Node b) {
	if(a.flag == false || b.flag == false) {
		return a.flag > b.flag;
	} else {
		return a.value < b.value;
	}	
}

Node list[maxn];

int main() {
	int n;
	int start;
	scanf("%d %d",&n,&start);
	
	for(int i=0;i<n;++i) {
		int add;
		int val;
		int nex;
		scanf("%d %d %d",&add,&val,&nex);
		list[add].address=add;
		list[add].value=val;
		list[add].next=nex;
	}
	int cnt=0;
	for(int i=start;i!=-1;i=list[i].next) {
		list[i].flag=true;
		cnt++;
	}
	
	if(cnt==0) {
		printf("0 -1");
		return 0;
	}
	sort(list,list+maxn,cmp);
	
	start=list[0].address;
	
	printf("%d %05d\n",cnt ,start);
	
	for(int i=0;i<cnt;++i) {
		if(i==cnt-1) {
			printf("%05d %d %d\n",list[i].address,list[i].value,-1);
		} else {
			printf("%05d %d %05d\n",list[i].address,list[i].value,list[i+1].address);
		}
	}
	return 0;
}
