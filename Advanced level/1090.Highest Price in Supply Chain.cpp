#include<iostream>

#include<cstdio>

#include<vector>
using namespace std;

const int maxn=100000;

int supplier[maxn];

int findRoot(int i) {
	int layer=0;
	
	while(supplier[i]!=-1) {
		i=supplier[i];
		layer++;
	}
	return layer;
}

int n;
double p;
double r;
int main() {
	cin>>n>>p>>r;
	
	for(int i=0;i<n;++i) {
		cin>>supplier[i];
	}
	
	int maxn=0;
	int num=0;
	for(int i=0;i<n;++i) {
		int temp=findRoot(i);
		if(temp>maxn) {
			maxn=temp;
		}
	}
	for(int i=0;i<n;++i) {
		if(findRoot(i)==maxn) {
			num++;
		}
	}
	double price=p;
	for(int i=0;i<maxn;++i) {
		price*=(1+(r/100.0));
	}
	printf("%.2f %d",price,num);
	
	return 0;
}
