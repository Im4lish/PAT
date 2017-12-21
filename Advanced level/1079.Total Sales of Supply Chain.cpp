#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 100000;

struct Node {
	int sales = 0;
	bool isR = false;
	vector<int> child;
	int layer;
};

double sum = 0;
int n;
double p;
double r;


Node chain[maxn];

void dfs(Node n) {
	if (n.isR == true) {
		double price = p*pow(1 + r,n.layer);
		sum += n.sales*price;
	}
	else {
		for (int i = 0; i<n.child.size(); ++i) {

			chain[n.child[i]].layer = n.layer + 1;
			dfs(chain[n.child[i]]);
		}
	}
}

int main() {
	cin >> n >> p >> r;
	r = r / 100.0;
	int k;
	int id;
	int sale;
	for (int i = 0; i<n; ++i) {
		cin >> k;
		if (k == 0) {
			cin >> sale;
			chain[i].sales = sale;
			chain[i].isR = true;
		}
		else {
			for (int j = 0; j<k; ++j) {
				cin >> id;
				chain[i].child.push_back(id);
			}
		}
	}
	chain[0].layer = 0;
	dfs(chain[0]);

	printf("%.1lf", sum);
	return 0;
}
