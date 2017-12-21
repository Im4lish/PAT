#include<iostream>

using namespace std;

int main() {
	int n;
	int m;
	int num[1010];
	fill(num,num+1010,0);
	cin>>n>>m;
	for(int i=0;i<n;++i) {
		int temp;
		cin>>temp;
		num[temp]++;
	}
	for(int i=0;i<m;++i) {
		if(num[i] !=0) {
			num[i]--;
			if(num[m-i] != 0) {
				cout<<i<<" "<<m-i;
				return 0;
			}
			num[i]++;
		}
	}
	cout<<"No Solution";
	return 0;
} 
