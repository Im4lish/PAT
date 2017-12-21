#include<iostream>

using namespace std;

const int inf=999999;
const int maxn=550;
int n;
int m;
int C1;
int C2;

int dis[maxn];
int g[maxn][maxn];
int weight[maxn];
int w[maxn];
bool visit[maxn];
int num[maxn];

void dij(int s) {
	dis[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<n;++i) {
		int u=-1;
		int min=inf;
		for(int j=0;j<n;++j) {
			if(visit[j] == false && dis[j] < min) {
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) {
			return;
		}
		visit[u] =true;
		for(int v=0;v<n;++v) {
			if(visit[v] == false && g[u][v] != inf) {
				if(dis[v] > dis[u] + g[u][v]) {
					dis[v] = dis[u] + g[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				} else if (dis[v] == dis[u] + g[u][v]) {
					num[v] = num[v]+num[u];
					if(w[v] < w[u] + weight[v]) {
						w[v] = w[u]+weight[v];
					}
						
				}
			}
		}
	}
	
}

int main() {
	fill(visit,visit+maxn,false);
	fill(dis,dis+maxn,inf);
	fill(g[0],g[0]+maxn*maxn,inf);
	fill(w,w+maxn,0);
	fill(num,num+maxn,0);
	cin>>n>>m>>C1>>C2;
	for(int i=0;i<n;++i) {
		cin>>weight[i];
	}
	for(int i=0;i<m;++i) {
		int c1;
		int c2;
		int len;
		cin>>c1>>c2>>len;
		g[c1][c2]=len;
		g[c2][c1]=len;
	}
	dij(C1);
	cout<<num[C2]<<" "<<w[C2];
	return 0;
} 
