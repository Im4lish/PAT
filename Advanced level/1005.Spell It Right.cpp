#include<iostream>
#include<string>
#include<cstdio>
#include<cstring> 
using namespace std;

string spell[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
	string num;
	cin>>num;
	int sum=0;
	for(int i=0;i<num.size();++i) {
		sum+=(num[i]-'0');
	}
	char ans[200];
	sprintf(ans,"%d",sum);
	int len = strlen(ans);
	for(int i=0;i<len;++i) {
		if(i == 0) {
			cout<<spell[(ans[i]-'0')];
		} else {
			cout<<" "<<spell[(ans[i]-'0')];
		}
	}
	return 0;
} 
