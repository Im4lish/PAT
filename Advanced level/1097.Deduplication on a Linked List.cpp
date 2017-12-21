#include<iostream>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;

struct Node {
	int adress;
	int key;
	int next;
};

Node list[100000];
vector<Node> list1;
vector<Node> list2;
bool exist[10000]={false};

int main() {
	int start;
	int n;
	cin>>start>>n;
	int adress;
	int key;
	int next;
	for(int i=0;i<n;++i) {
		cin>>adress>>key>>next;
		list[adress].adress=adress;
		list[adress].key=key;
		list[adress].next=next;
	}

	for(int i=start;i!=-1;i=list[i].next) {
		int k=list[i].key > 0 ? list[i].key : -list[i].key;
		if(exist[k] == false) {
			exist[k]=true;
			list1.push_back(list[i]);
		} else {
			list2.push_back(list[i]);
		}
	}
	
	
	for(int i=0;i<list1.size();++i) {
		if(i==list1.size()-1){
			printf("%05d %d -1\n",list1[i].adress,list1[i].key);
		} else {
			printf("%05d %d %05d\n",list1[i].adress,list1[i].key,list1[i+1].adress);
		}
	}
	for(int i=0;i<list2.size();++i) {
		if(i==list2.size()-1){
			printf("%05d %d -1\n",list2[i].adress,list2[i].key);
		} else {
			printf("%05d %d %05d\n",list2[i].adress,list2[i].key,list2[i+1].adress);
		}
	}
	return 0;
}
