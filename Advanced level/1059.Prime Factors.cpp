#include<iostream>
#include<vector>
using namespace std;

const long long int maxn=5000000;

vector<bool> prime(maxn,true);

void process() {
	for(int i=2;i<maxn;++i) {
		for(int j=2;i*j<maxn;++i) {
			prime[i*j]=false;
		}
	}
}

int n;


int main() {
	process();
	cin>>n;
	if(n==1) {
		cout<<"1=1";
		return 0; 
	} 
	cout<<n<<"=";
	bool notfirst=false;
	
	for(int i=2;n>=2&&i<maxn;++i) {
		int cnt=0;
		bool flag=false;
		while(prime[i]==true && n%i==0) {
			cnt++;
			n=n/i;
			flag=true;
		}
		if(flag) {
			if(notfirst) {
				cout<<"*";
			}
			cout<<i;
			notfirst=true;
		}
		if(cnt>=2) {
			cout<<"^"<<cnt;
		}
	} 
	
	return 0;
}
