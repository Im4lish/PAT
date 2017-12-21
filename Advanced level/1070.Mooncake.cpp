#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

struct moonCake {
	double per;
	double price;
	double weight;
};

bool cmp(moonCake a,moonCake b) {
	return a.per>b.per;
}

int main() {
	int n;
	
	int d;
	cin>>n>>d;
	vector<moonCake> cake(n);
	for(int i=0;i<n;++i) {
		cin>>cake[i].weight;
	}
	for(int i=0;i<n;++i) {
		cin>>cake[i].price;
		cake[i].per=cake[i].price / cake[i].weight;
	}
	sort(cake.begin(),cake.end(),cmp);
	double sum=0;
	for(int i=0;i<n;++i) {
		if(cake[i].weight < d) {
			sum+=cake[i].price;
		} else {
			sum+=d*cake[i].per;
			break;
		}
		d-=cake[i].weight;  
	}
	printf("%.2f",sum);
	return 0;
}
