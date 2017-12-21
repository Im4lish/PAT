#include <iostream>  
#include <vector>  
#include <cstdio>  
#include <algorithm>  
 
using namespace std;
 
vector<int> tree;
vector<int> nodes;
int N;
 
void build(int root) {
    static int index = 1;
    if (root > N) return;
    build(root * 2);
    tree[root] = nodes[index++];
    build(root * 2 + 1);
}
 
int main()
{
    cin >> N;
    nodes.resize(N + 1);
    tree.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &nodes[i]);
    }
    sort(nodes.begin()+1, nodes.end());
    build(1);
    printf("%d", tree[1]);
    for (int i = 2; i <= N; i++)
        printf(" %d", tree[i]);
    cout << endl;
    return 0;
}
