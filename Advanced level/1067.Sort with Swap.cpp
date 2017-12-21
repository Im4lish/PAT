#include<iostream>
#include<vector>
using namespace std;

const int maxn=100000;

vector<int> arr(maxn);

int main() {
	int n;
	cin>>n;
	arr.resize(n);
	int cnt=0;
	for(int i=0;i<n;++i) {
		int num;
		cin>>num;
		arr[num]=i;
		if(num != i && num != 0) {
			cnt++;
		}
	}
	
	int ans=0;
	int index=1;
	while(cnt>0) {
		if(arr[0] == 0) {
			while(index<n) {
				if(arr[index] != index) {
					swap(arr[0],arr[index]);
					ans++;
					break;
				}
				index++;
			}
		}
		while(arr[0] != 0) {
			swap(arr[arr[0]],arr[0]);
			ans++;
			cnt--;
		}
	}
	cout<<ans;
	return 0;
}
