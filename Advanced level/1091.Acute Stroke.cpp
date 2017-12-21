#include<iostream> 
#include<queue>
using namespace std;
struct Node {
	int x;
	int y;
	int z;
};

bool visit[1300][130][70];
int g[1300][130][70];
int m;
int n;
int l;
int t;

bool check(int x,int y,int z) {
	if(x<0 || x>=m || y<0 || y>=n || z<0 || z>=l) {
		return false;
	}
	return true;
}

int BFS(int x,int y,int z) {
	queue<Node> q;
	int arrx[6]={1,0,0,-1,0,0};
	int arry[6]={0,1,0,0,-1,0};
	int arrz[6]={0,0,1,0,0,-1};
	Node temp;
	temp.x=x;
	temp.y=y;
	temp.z=z;
	int cnt=1;
	q.push(temp);
	visit[x][y][z]=true; 
	while(!q.empty()) {
		Node top=q.front();
		q.pop();
		for(int i=0;i<6;++i) {
			int tempx=top.x+arrx[i];
			int tempy=top.y+arry[i];
			int tempz=top.z+arrz[i];
			if(check(tempx,tempy,tempz)) {
				if(g[tempx][tempy][tempz] == 1 && visit[tempx][tempy][tempz]==false) {
					temp.x=tempx;
					temp.y=tempy;
					temp.z=tempz;
					q.push(temp);
					cnt++;
					visit[tempx][tempy][tempz]=true;
				}
			}
		}
		
	}
	if(cnt>=t) {
		return cnt;
	} else {
		return 0;
	}
}

int main() {
	cin>>m>>n>>l>>t;
	int sum=0;
	for(int i=0;i<l;++i) {
		for(int j=0;j<m;++j) {
			for(int k=0;k<n;++k) {
				cin>>g[j][k][i];
			}
		}
	}
	for(int i=0;i<l;++i) {
		for(int j=0;j<m;++j) {
			for(int k=0;k<n;++k) {
				if(g[j][k][i]==1 && visit[j][k][i]==false) {
					sum+=BFS(j,k,i);
				}
			}
		}
	}
	cout<<sum;
	return 0;
} 
