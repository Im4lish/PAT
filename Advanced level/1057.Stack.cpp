#include<iostream>

#include<set>
#include<string>
#include<stack>
using namespace std;

multiset<int> mins;
multiset<int> maxs;
stack<int> s;

string push = "Push";
string pop = "Pop";
string peekmdedian = "PeekMedian";
string invalid = "Invalid";

int n;
int num;
int top;

int mid=-1;

void adjust() {
	if(maxs.size()+1<mins.size()) {
		auto it = mins.end();
		--it;
		maxs.insert(*it);
		mins.erase(it);
	} else if(maxs.size()>mins.size()) {
		auto it = maxs.begin();

		mins.insert(*it);
		maxs.erase(it);
	}
	if(s.size()>0) {
		auto it=mins.end();
		--it;
		mid=*it;
	}
}

int main() {
	cin>>n;
	string cmd;
	for(int i=0;i<n;++i) {
		cin>>cmd;
		if(cmd==push) {
			cin>>num;
			if(s.empty()) {
				mins.insert(num);
				mid=num;
			} else {
				if(num<=mid) {
					mins.insert(num);
				} else {
					maxs.insert(num);
				}
			}
			s.push(num);
			adjust();
		} else if(cmd==pop) {
			if(s.empty()) {
				cout<<invalid; 
			} else {
				top=s.top();
				s.pop();
				cout<<top;
				if(mid>=top) {
					auto it=mins.find(top);
					mins.erase(it);
				} else {
					auto it=maxs.find(top);
					maxs.erase(it);
				}
			} 
			cout<<endl;
		} else if(cmd==peekmdedian) {
			if(s.empty()) {
				cout<<invalid; 
			} else {
				cout<<mid;
			} 
			cout<<endl;
		} else {
			cout<<invalid<<endl;
		}
	}
	return 0;
}
