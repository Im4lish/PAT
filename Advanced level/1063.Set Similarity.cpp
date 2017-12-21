#include<iostream> 
#include<set>
#include<cstdio>
#include<vector>
using namespace std;



vector<set<int> > s;


int n;
int m;
int k;
int a;
int b;
int num;
int main() {
	scanf("%d",&n);
	s.resize(n+1);
	for(int i=1;i<=n;++i) {
		scanf("%d:",&m);
		for(int j=0;j<m;j++) {
			scanf("%d",&num);
			s[i].insert(num);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;++i) {
		scanf("%d %d",&a,&b);
		int sizea=s[a].size();
		int sizeb=s[b].size();
		int nc=0;
		int nt=sizeb;
		for(auto it=s[a].begin();it != s[a].end();it++) {
			if(s[b].find(*it) != s[b].end()) {
				nc++;
			} else {
				nt++;
			}
		} 
		printf("%.1f%%\n",nc*100.0/nt);
		
	}
	return 0;
	
	
}
