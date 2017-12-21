#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	long long a;
	long long b;
	long long c;
	long long sum=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		
		scanf("%lld %lld %lld", &a, &b, &c);
		bool flag=false;
		sum=a+b;
		if(a>0 && b>0 && sum<0) {
			flag=true;
		} else if(a<0 && b<0 && sum>=0) {
			flag=false;
		} else {
			flag=sum>c;
		}
		if(flag==true) {
			printf("Case #%d: true\n",i);
		} else {
			printf("Case #%d: false\n",i);
		}
	}
	return 0;
}
