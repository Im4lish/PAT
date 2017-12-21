#include<iostream>

using namespace std;

const int maxn=1010;

bool g[maxn][maxn];
bool visit[maxn];

int n;
int m;
int k;

void dfs(int s) {
	visit[s] = true;
	for(int i=1;i<=n;++i) {
		if(visit[i] == false && g[s][i] == true) {
			dfs(i);
		}
	}
}

int main() {
	fill(g[0],g[0]+maxn*maxn,false);
	fill(visit,visit+maxn,false); 

	cin>>n>>m>>k;
	for(int i=0;i<m;++i) {
		int a;
		int b;
		cin>>a>>b;
		g[a][b]=true;
		g[b][a]=true;
	}
	for(int i=0;i<k;++i) {
		fill(visit,visit+maxn,false); 
		int num;
		cin>>num;
		int cnt = 0;
		visit[num] = true;
		for(int j=1;j<=n;++j) {
			if(visit[j] == false) {
				dfs(j);
				cnt++;
			}
		}
		cout<<cnt-1<<endl;
	}
	return 0;
}
