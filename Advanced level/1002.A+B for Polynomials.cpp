#include<iostream>
#include<vector>
#include<cstdio> 
using namespace std;

const int maxn=1010;

double sum[maxn];

int main() {
	fill(sum,sum+maxn,0);
	vector<int> pos;
	int k;
	int n;
	cin>>k;
	for(int i=0;i<k;++i) {
		cin>>n;
		double a;
		cin>>a;
		sum[n]+=a;
	}
	cin>>k;
	for(int i=0;i<k;++i) {
		cin>>n;
		double a;
		cin>>a;
		sum[n]+=a;
	}
	for(int i=0;i<maxn;++i) {
		if(sum[i] != 0) {
			pos.push_back(i);
		}
	}
	
	cout<<pos.size();
	for(int i=pos.size()-1;i>=0;--i) {
		printf(" %d %.1f",pos[i],sum[pos[i]]);
	}
	return 0;
}
