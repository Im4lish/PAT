#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Node {
	int id;
	string name;
	int grade;
};

const int maxn=100100;

Node node[maxn];

bool cmp1(Node a,Node b) {
	return a.id<b.id;
}

bool cmp2(Node a,Node b) {
	return a.name<=b.name;
}

bool cmp3(Node a,Node b) {
	return a.grade<=b.grade;
}

int main() {
	int n;
	int c;
	cin>>n>>c; 
	for(int i=0;i<n;++i) {
		cin>>node[i].id>>node[i].name>>node[i].grade;
	}
	if(c == 1) {
		sort(node,node+n,cmp1);
	} else if (c == 2) {
		sort(node,node+n,cmp2);
	} else if (c == 3) {
		sort(node,node+n,cmp3);
	}
	for(int i=0;i<n;++i) {
		printf("%06d ",node[i].id);
		cout<<node[i].name<<" "<<node[i].grade<<endl;
	}
	return 0;
} 
