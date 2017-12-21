#include<iostream>
#include<string>
#include<map>
#include<cctype>

using namespace std;

int main() {
	string s;
	getline(cin,s);
	string ans="";
	map<string,int> m;
	for(int i=0;i<s.size();++i) {
		if(isalnum(s[i])) {
			s[i]=tolower(s[i]);
			ans = ans+s[i];
		} 
		if(!isalnum(s[i]) || i == s.size()-1) {
			if(ans.size() != 0) {
				m[ans]++;
			}
			ans="";
		}
	}
	int maxn=0;
	for(auto it = m.begin();it != m.end();++it) {
		if(it->second >maxn) {
			maxn=it->second;
			ans=it->first;
		}
	}
	
	cout<<ans<<" "<<maxn; 
	return 0;
}
