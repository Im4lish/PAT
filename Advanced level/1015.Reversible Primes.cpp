#include<iostream> 
#include<cstdio>
#include<cmath>
using namespace std;

bool isPrime(int num) {
	if(num <= 1) {
		return false;
	}
	int sqr = sqrt(num);
	for(int i=2;i<=sqr;++i) {
		if(num % i == 0) {
			return false;
		}
	} 
	return true;
}

int n;
int d;

int main() {
	while(scanf("%d",&n)  != EOF) {
		if(n < 0) {
			break;
		}
		scanf("%d",&d);
		if(isPrime(n) == false) {
			printf("No\n");
			continue;
		}
		int len=0;
		int arr[100];
		do{
			arr[len++] = n%d;
			n/=d;
		}while(n!=0);
		for(int i=0;i<len;++i) {
			n = n*d+arr[i];
		}
		if(isPrime(n) == false) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}
