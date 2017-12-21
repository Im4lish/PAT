#include<iostream>
#include<vector> 
#include<queue>
using namespace std;

struct Node {
	int id;
	int layer=0;
};

const int maxn=1000;
vector<int> user[maxn];
int n;
int l;
int query;

int cal(Node node) {
	bool inq[maxn]={false};
	queue<Node> q;
	q.push(node);
	inq[node.id]=true;
	int cnt=0;
	while(!q.empty()) {
		Node now = q.front();
		q.pop();
		int userid=now.id;
		for(int i=0;i<user[userid].size();++i) {
			int nextid=user[userid][i];
			if(inq[nextid] == false && now.layer<l) {
				Node next;
				next.id=nextid;
				next.layer=now.layer+1;
				q.push(next);
				inq[nextid]=true;
				cnt++;
				
			}
		}
	}
	return cnt;
}

int main() {
	cin>>n>>l;
	
	for(int i=1;i<=n;++i) {
		int follow;
		cin>>follow;
		for(int j=0;j<follow;++j) {
			int id;
			cin>>id;
			user[id].push_back(i);
		}
	}
	
	cin>>query;
	for(int i=0;i<query;++i) {
		int id;
		cin>>id;
		Node n;
		n.id=id;
		cout<<cal(n)<<endl;
	}
	
	return 0;
}
