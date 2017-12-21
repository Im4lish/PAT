#include<iostream>
#include<cmath>
using namespace std;

const int maxn=10000;

bool h[maxn]={false};

bool isPrime(int n) {
	if(n==1) {
		return false;
	}
	int s=sqrt(n);
	for(int i=2;i<=s;++i) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}

int findPrime(int n) {
	while(1) {
		if(isPrime(n)) {
			return n;
		}
		n++;
	}	
}

int msize,n;

int main() {
	cin>>msize>>n;
	int size=findPrime(msize);
	for(int i=0;i<n;++i) {
		if(i!=0) {
			cout<<" ";
		}
		int num;
		cin>>num;
		int p=num%size;
		int flag=false;
		if(h[p]==false) {
			cout<<p;
			h[p]=true;
			continue;
		} else {
			for(int step=1;step<size;step++) {
				p=(num+step*step)%size;
				if(h[p]==false) {
					cout<<p;
					h[p]=true;
					flag=true;
					break;
				}
			}
		}
		
		if(flag==false) {
			cout<<"-";
		}
			
	}  
	return 0;
}
