#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int maxn=41111;

string person[maxn];
vector<int> course[maxn];

bool cmp(int a,int b) {
	return person[a]<person[b];
}

int main() {
	int n;
	int k;
	
	cin>>n>>k;
	
	for(int i=1;i<=n;++i) {
		string stu;
		int m;
		cin>>stu>>m;
		person[i]=stu;
		for(int j=0;j<m;++j) {
			int temp;
			cin>>temp;
			course[temp].push_back(i);
		}
	}
	for(int i=1;i<=k;++i) {
		sort(course[i].begin(),course[i].end(),cmp);
		cout<<i<<" "<<course[i].size()<<endl;
		for(int j=0;j<course[i].size();++j) {
			cout<<person[course[i][j]]<<endl;
		}
	}
	
	return 0;
}
