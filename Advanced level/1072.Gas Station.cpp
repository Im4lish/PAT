#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
const int inf=999999;

const int maxn=1020;

int dis[maxn];
int g[maxn][maxn];
bool visit[maxn];

using namespace std;

int main() {
	int n;
	int m;
	int k;
	int ds;
	fill(dis,dis+maxn,inf);
	fill(g[0],g[0]+maxn*maxn,inf);
	cin>>n>>m>>k>>ds;
	for(int i=0;i<k;++i) {
		int temp;
		string sa;
		string sb;
		cin>>sa>>sb>>temp;
		int a;
		int b;
		if(sa[0] == 'G') {
			sa=sa.substr(1);
			a=n+stoi(sa);
		} else {
			a=stoi(sa);
		}
		if(sb[0] == 'G') {
			sb=sb.substr(1);
			b=n+stoi(sb);
		} else {
			b=stoi(sb);
		}
		g[a][b]=temp;
		g[b][a]=temp;
	}
	int ansid=-1;
	double ansdis=-1;
	double ansave=inf;
	for(int index=n+1;index<=n+m;++index) {
		double mindis=inf;
		double ave=0;
		fill(dis,dis+maxn,inf);
		fill(visit,visit+maxn,false);
		dis[index]=0;
		for(int i=0;i<n+m;++i) {
			int u=-1;
			int minn=inf;
			for(int j=1;j<=n+m;++j) {
				if(visit[j] == false && dis[j]<minn) {
					u=j;
					minn=dis[j];
				}
			}
			if(u==-1) {
				break;
			}
			visit[u]=true;
			for(int v=1;v<=n+m;v++) {
				if(visit[v] == false && g[u][v] != inf && dis[v]>dis[u]+g[u][v]) {
					dis[v]=dis[u]+g[u][v];
				}
			}
		}
		for(int i=1;i<=n;++i) {
			if(dis[i]>ds) {
				mindis=-1;
				break;
			}
			if(dis[i]<mindis) {
				mindis=dis[i];
			}
			ave+=1.0*dis[i];			
		}
		if(mindis == -1) {
			continue;
		}
		ave=ave/n;
		if(mindis<ansdis) {
			ansid=index;
			ansdis=mindis;
			ansave=ave;
		} else if (mindis==ansdis && ave<ansave) {
			ansid=index;
			ansave=ave;
		}
		
	}
	if(ansid == -1) {
		printf("NO Solution");
	} else {
		printf("G%d\n%.1f %.1f",ansid,ansdis,ansave);
	}
	return 0;
} 
