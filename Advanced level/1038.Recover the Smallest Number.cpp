#include<iostream>
#include<vector> 
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a,string b) {
	return a+b < b+a;
}
int main() {
	int n;
	cin>>n;
	vector<string> vec(n);
	for(int i=0;i<n;++i) {
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end(),cmp);
	string ans;
	for(int i=0;i<n;++i) {
		ans += vec[i];
	}
	while(ans.size() != 0 && ans[0] == '0') {
		ans.erase(ans.begin());
	}
	if(ans.size() == 0) {
		cout<<0;
	} else {
		cout<<ans;
	}
	return 0;
} 
