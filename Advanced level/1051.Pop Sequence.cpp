#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	int m;
	int n;
	int k;
	cin>>m>>n>>k;
	for(int i=0;i<k;++i) {
		stack<int> s;
		vector<int> v(n+1);
		int  cur=1;
		for(int j=1;j<=n;++j) {
			cin>>v[j];
			
		}
		for(int j=1;j<=n;++j) {
			s.push(j);
			if(s.size() > m) {
				break;
			}
			while(!s.empty() && s.top() == v[cur]) {
				s.pop();
				cur++;
			}
		}
		if(cur == n + 1) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0; 
} 
