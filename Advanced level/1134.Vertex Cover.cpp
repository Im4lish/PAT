#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	int m;
	cin>>n>>m;
	vector<int> vec[n];
	for(int i=0;i<m;++i) {
		int a;
		int b;
		cin>>a>>b;
		vec[a].push_back(i);
		vec[b].push_back(i);
	}
	bool isCover[m];
	
	int k;
	cin>>k;
	for(int i=0;i<k;++i) {
		fill(isCover,isCover+m,false);
		int nv;
		cin>>nv;
		for(int j=0;j<nv;++j) {
			int id;
			cin>>id;
			int size = vec[id].size();
			for(int k=0;k<size;++k) {
				isCover[vec[id][k]] = true;
			}
		}
		bool flag = true;
		for(int i=0;i<m;++i) {
			if(isCover[i] == false) {
				flag=false;
				break;
			}
		}
		if(flag == true) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}
		
		
	}
	
	return 0;
} 
