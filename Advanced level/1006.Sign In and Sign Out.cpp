#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

struct Person {
	string id;
	int intime;
	int outtime;
};


int main() {
	int n;
	cin>>n;
	vector<Person> vec(n);
	int minid;
	int maxid;
	int tempmax=0;
	int tempmin=24*60*60;
	for(int i=0;i<n;++i) {
		string tempid;
		int tempin;
		int tempout;
		int inhh;
		int inmm;
		int inss;
		int outhh;
		int outmm;
		int outss;
		cin>>tempid;
		scanf("%d:%d:%d %d:%d:%d",&inhh,&inmm,&inss,&outhh,&outmm,&outss);
		tempin=inhh*3600+inmm*60+inss;
		tempout=outhh*3600+outmm*60+outss;
		vec[i].id=tempid;
		vec[i].intime=tempin;
		vec[i].outtime=tempout;
		if(tempout > tempmax) {
			maxid=i;
			tempmax=tempout;
		}
		if(tempin < tempmin) {
			minid=i;
			tempmin=tempin;
		}
	}
	cout<<vec[minid].id<<" "<<vec[maxid].id;
	return 0;
}
