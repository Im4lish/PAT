#include<iostream>
#include<vector>
using namespace std;

const int maxn=10100;

int cnt[maxn];

int main() {
	fill(cnt,cnt+maxn,0);
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i=0;i<n;i++) {
		cin>>v[i];
		cnt[v[i]]++;
	}
	
	for(int i=0;i<n;i++) {
		if(cnt[v[i]] == 1) {
			cout<<v[i];
			return 0;
		}
	}
	cout<<"None";
	return 0;
}
