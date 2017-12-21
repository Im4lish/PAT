
#include<iostream>  
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include <algorithm>
using namespace std;

const int maxn = 205;
const int inf = 999999;

int n;//number of cities
int k;//number of roads
string startCity;//starting city

map<string, int> msToi;
map<int, string> miTos;

int g[maxn][maxn];
int dis[maxn];
int weight[maxn];
bool visit[maxn];

vector<int> pre[maxn];
vector<int> path;
vector<int> tempPath;

int maxHappiness = 0;
int maxAverage = 0;
int count = 0;


void DFS(int s) {
	tempPath.push_back(s);

	if (s == 1) {
		::count++;
		int value = 0;
		for (int i = tempPath.size() - 1; i >= 0; --i) {
			value += weight[tempPath[i]];
		}
		int tempAvrage = value*1.0 / (tempPath.size() - 1);
		if (value>maxHappiness) {
			maxHappiness = value;
			maxAverage = tempAvrage;
			path = tempPath;
		}
		else if (value == maxHappiness && tempAvrage>maxAverage) {
			maxAverage = tempAvrage;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	for (int i = 0; i < pre[s].size(); i++) {
		DFS(pre[s][i]);
	}
	tempPath.pop_back();
}

void Dijkstra(int s) {
	dis[s] = 0;
	for (int i = 0; i<n; ++i) {
		int u = -1;
		int minn = inf;
		for (int i = 1; i<=n; ++i) {
			if (visit[i] == false && dis[i]<minn) {
				u = i;
				minn = dis[i];
			}
		}
		if (u == -1) {
			return;
		}
		visit[u] = true;
		for (int i = 1; i<=n; ++i) {
			if (visit[i] == false && g[u][i] != inf) {
				if (dis[i] > dis[u] + g[u][i]) {
					dis[i] = dis[u] + g[u][i];
					pre[i].clear();
					pre[i].push_back(u);
				}
				else if (dis[i] == dis[u] + g[u][i]) {
					pre[i].push_back(u);
				}
			}
		}
	}
}


int main() {
	fill(g[0], g[0] + maxn*maxn, inf);
	fill(dis, dis + maxn, inf);
	scanf("%d%d", &n, &k);
	cin >> startCity;
	msToi[startCity] = 1;
	miTos[1] = startCity;
	string city;

	for (int i = 1; i<n; i++) {
		cin >> city >> weight[i + 1];
		msToi[city] = i + 1;
		miTos[i + 1] = city;
	}
	string city1;
	string city2;
	int cost;
	for (int i = 0; i<k; ++i) {
		cin >> city1 >> city2 >> cost;
		g[msToi[city1]][msToi[city2]] = cost;
		g[msToi[city2]][msToi[city1]] = cost;
	}

	Dijkstra(1);
	int a;
	int rom = msToi["ROM"];
	DFS(rom);
	printf("%d %d %d %d\n", ::count, dis[rom], maxHappiness, maxAverage);
	
	for (int i = path.size() - 1; i>0; --i) {
		cout << miTos[path[i]] << "->";
	}
	printf("ROM");

	return 0;
}
