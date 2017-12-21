#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=26*26*26*10+10;

vector<int> list[maxn];

int toint(char* name) {
	int sum=0;
	for(int i=0;i<3;++i) {
		sum = sum + (name[i]-'A')*26;
	}
	sum = sum + (name[3]-'0')*10;
	return sum;
}

int main() {
	int n;
	int k;
	cin>>n>>k;
	for(int i = 0;i<k;++i) {
		int classid;
		int num;
		cin>>classid>>num;
		for(int j=0;j<num;++j) {
			char name[5];
			scanf("%s",name);
			list[toint(name)].push_back(classid);
		}
	}
	for(int i=0;i<n;++i) {
		char name[5];
		scanf("%s",name);
		printf("%s",name);
		int id=toint(name);
		printf(" %d",list[id].size());\
		sort(list[id].begin(),list[id].end());
		for(int j=0;j<list[id].size();++j) {
			printf(" %d",list[id][j]);
			if(j == list[id].size() - 1) {
				printf("\n");
			}
		}
	}
	return 0;
} 
