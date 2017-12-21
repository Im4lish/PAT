#include<iostream>

using namespace std;

int num[100];
int len=0;

bool isPalindromic() {
	int half = len/2;
	for(int i=0;i<half;++i) {
		if(num[i] != num[len-1-i]) {
			return false;
			
		}
	}
	return true;
}
	

int main() {
	int n;
	int b;
	cin>>n>>b;
	
	do{
		num[len++] = n % b;
		n = n / b;
	}while(n != 0);
	if(isPalindromic() == true) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}
	for(int i=len-1;i>=0;--i) {
		if(i == len-1) {
			cout<<num[i];
		} else {
			cout<<" "<<num[i];
		} 
	}
	
	return 0;
}
