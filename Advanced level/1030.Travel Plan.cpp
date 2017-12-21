#include<iostream>
#include<vector>

using namespace std;

const int maxn=510;
const int inf = 99999999;

int g[maxn][maxn];
int c[maxn][maxn];
int dis[maxn];
bool visit[maxn];
vector<int> pre[maxn];
vector<int> temppath,path;
int mincost = inf;

int n;
int m;
int s;
int d;


void dfs(int v) {
	if(s == v) {
		temppath.push_back(v);
		int tempcost=0;
		for(int i=temppath.size()-1;i>0;--i) {
			int id=temppath[i];
			int nextid=temppath[i-1];
			tempcost += c[id][nextid];
		}
		if(tempcost < mincost) {
			mincost = tempcost;
			path=temppath;
		}
		temppath.pop_back();
		return ;
	}
	temppath.push_back(v);
	for(int i=0;i<pre[v].size();++i) {
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}


int main() {
	fill(g[0],g[0]+maxn*maxn,inf);
	fill(dis,dis+maxn,inf);
	fill(visit,visit+maxn,false);
	cin>>n>>m>>s>>d;
	for(int i=0;i<m;++i) {
		int a;
		int b;
		int distance;
		int cost;
		cin>>a>>b>>distance>>cost;
		g[a][b]=distance;
		g[b][a]=distance;
		c[a][b]=cost;
		c[b][a]=cost;
	}
	pre[s].push_back(s);
	dis[s]=0;
	for(int i=0;i<n;++i) {
		int u=-1;
		int minn=inf;
		for(int j=0;j<n;++j) {
			if(visit[j] == false && dis[j] < minn) {
				u=j;
				minn=dis[j];
			}
		}
		if(u==-1) {
			break;
		}
		visit[u] = true;
		for(int v=0;v<n;++v) {
			if(visit[v] == false && g[u][v] != inf) {
				if(dis[u] + g[u][v] < dis[v]) {
					dis[v]=dis[u]+g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[u] + g[u][v] == dis[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(d);
	for(int i=path.size()-1;i>=0;--i) {
		cout<<path[i]<<" ";
	}
	cout<<dis[d]<<" "<<mincost;
	return 0;
}
