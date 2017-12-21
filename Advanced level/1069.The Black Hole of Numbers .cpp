#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;

bool cmp(char a,char b) {
	return a>b;
}

int main() {
	string a;
	string b;
	string num;
	cin>>num;
	num.insert(0,4-num.size(),'0');
	do {
		a=num;
		b=num;
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end());
		int result = stoi(a) - stoi(b);
		num=to_string(result);
		num.insert(0,4-num.size(),'0');
		cout<<a<<" - "<<b<<" = "<<num<<endl;
	} while(num !="6174" && num!="0000");
	return 0;
}
