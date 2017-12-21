#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct Node {
	int ex;
	double co;
};

const int maxn=2100;

double ans[maxn];

int main() {
	fill(ans,ans+maxn,0);
	vector<Node> a;
	vector<Node> b;

	int n1;
	int n2;
	cin>>n1;
	a.resize(n1);
	for(int i=0;i<n1;++i) {
		cin>>a[i].ex>>a[i].co;
	}
	cin>>n2;
	b.resize(n2);
	for(int i=0;i<n2;++i) {
		cin>>b[i].ex>>b[i].co;
		for(int j=0;j<a.size();++j) {
			ans[a[j].ex+b[i].ex] += a[j].co*b[i].co;
		}
	}
	int cnt=0;
	for(int i=0;i<maxn;++i) {
		if(ans[i] != 0) {
			cnt++;
		} 
	}
	cout<<cnt;
	for(int i=maxn-1;i>=0;--i) {
		if(ans[i] != 0) {
			printf(" %d %.1f",i,ans[i]);
		}
			
	}
	return 0;
}
