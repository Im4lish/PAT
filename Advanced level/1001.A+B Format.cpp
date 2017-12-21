#include<iostream>
#include<string>
#include<cstring> 
#include<cstdio>
using namespace std;

int main() {
	int a;
	int b;
	
	cin>>a>>b;
	int sum=a+b;
	char str[100];
	sprintf(str,"%d",sum);
	int len = strlen(str);
	/*
	string str = to_string(sum);
	int len = str.length();
	*/
	for(int i=0;i<len;++i) {
		cout<<str[i];
		if(str[i] == '-') {
			continue;
		}
		if((i+1)%3 == len%3 && i != len-1) {
			cout<<",";
		}
	}
	return 0;
}
