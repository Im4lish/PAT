#include<cstdio>

#include<vector>

using namespace std;

const int maxn = 510;
const int inf = 999999;

bool visit[maxn]={false};
int G[maxn][maxn];
int weight[maxn];
int dis[maxn];

vector<int> pre[maxn];
vector<int> path;
vector<int> tempPath;
int Cmax , N , Sp , M;

int minNeed=inf,minBack=inf;

void DFS(int start) {
	if(start == 0) {
		tempPath.push_back(start);
		int need=0,back=0;
		for(int i=tempPath.size()-1;i>=0;--i) {
			int id=tempPath[i];
			if(weight[id] > 0) {
				back += weight[id];
			} else if(back + weight[id] >0) {
				back += weight[id];
			} else {
				need += ((-weight[id])-back);
				back=0;
			} 
		}
		if(need<minNeed) {
			minNeed=need;
			minBack=back;
			path=tempPath; 
		} else if(need == minNeed && back < minBack) {
			minBack=back;
			path=tempPath; 
		}
		tempPath.pop_back();
        return ;
	}
	tempPath.push_back(start);
	for(int i=0;i<pre[start].size();++i) {
		DFS(pre[start][i]);
	}
	tempPath.pop_back();
}

void Dijkstra(int start) {
	
	dis[start] = 0;
	for(int i=0;i<=N;++i) {
		int u=-1;
		int Min=inf;
		for(int i=0;i<=N;++i) {
			if(visit[i] == false && dis[i]<Min) {
			u=i;
			Min=dis[i];
			} 
		}
		
		if(u==-1) {
			return;
		}
		visit[u]=true;
		for(int i=0;i<=N;++i) {
			if(visit[i] == false && G[u][i] !=inf) {
				if(dis[u] + G[u][i] < dis[i]) {
					dis[i] = dis[u] + G[u][i];
					pre[i].clear();
					pre[i].push_back(u); 
				} else if(dis[u] + G[u][i] == dis[i]) {
					pre[i].push_back(u); 
				}
			}
			
		}
	}
}

int main() {
	fill(G[0],G[0]+maxn*maxn,inf);
	fill(dis,dis+maxn,inf);
	scanf("%d%d%d%d", &Cmax,&N,&Sp,&M);
	int half = Cmax/2;
	for(int i=1;i<=N;++i) {
		scanf("%d",&weight[i]);
		weight[i]=weight[i]-half;
	}
	for(int i=0;i<M;++i) {
		int a,b,time;
		scanf("%d%d%d",&a,&b,&time);
		G[a][b]=time;
		G[b][a]=time;
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d 0",minNeed);
	for(int i=path.size()-2;i>=0;--i) {
		printf("->%d",path[i]);
	}
	printf(" %d",minBack);
	return 0;
} 
