#include<iostream>  
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn=100;

string s[maxn];

int n;

int main() {
	cin>>n;
	string ans;
	getchar();
	for(int i=0;i<n;++i) {
		getline(cin,s[i]);
		reverse(s[i].begin(),s[i].end());
		if(i==0) {
			ans=s[i];
		} else {
			int len=min(ans.size(),s[i].size());
			for(int j=0;j<len;++j) {
				if(s[i][j] != ans[j]) {
					ans=ans.substr(0,j);
				}
			}
		}
	}
	reverse(ans.begin(),ans.end());
	if(ans.size()==0) {
		cout<<"nai";
	} else {
		cout<<ans;
	}
	return 0;
}
