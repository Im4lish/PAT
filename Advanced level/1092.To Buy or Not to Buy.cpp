#include<iostream>
#include<map>
#include<string>
using namespace std;



int main() {
	string sale;
	string need;
	cin>>sale>>need;
	map<char,int> mapp;
	int miss=0;
	for(int i=0;i<sale.size();++i) {
		mapp[sale[i]]++;
	}
	for(int i=0;i<need.size();++i) {
		mapp[need[i]]--;
		if(mapp[need[i]] < 0) {
			miss++;
		}
	}
	if(miss==0) {
		cout<<"Yes "<<sale.size()-need.size();
	} else {
		cout<<"No "<<miss;
	}
} 
