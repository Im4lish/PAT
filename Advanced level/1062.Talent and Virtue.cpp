#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Person {
	int id;
	int vir;
	int tal;
};


vector<Person> v[4];

bool cmp(Person a,Person b) {
	if((a.tal+a.vir) != (b.tal+b.vir)) {
		return (a.vir+a.tal) >(b.vir+b.tal);
	} else if(a.vir != b.vir) {
		return a.vir > b.vir;
	} else {
		return a.id < b.id;
	}
}

int main() {
	int n;
	int low;
	int high;
	Person temp;
	cin>>n>>low>>high;
	int total=n;
	for(int i=0;i<n;++i) {
		cin>>temp.id>>temp.vir>>temp.tal;
		if(temp.tal < low || temp.vir < low) {
			total--;
		} else if(temp.tal>=high && temp.vir>=high) {
			v[0].push_back(temp);
		} else if(temp.vir>=high && temp.tal<high) {
			v[1].push_back(temp);
		} else if(temp.tal < high && temp.vir < high && temp.vir >= temp.tal) {
			v[2].push_back(temp);
		} else {
			v[3].push_back(temp);
		}
	}
	cout<<total<<endl;
	for(int i=0;i<4;++i) {
		sort(v[i].begin(),v[i].end(),cmp);
		for(int j=0;j<v[i].size();++j) {
			cout<<v[i][j].id<<" "<<v[i][j].vir<<" "<<v[i][j].tal<<endl; 
		}
	}
	return 0;
}
