#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	int sum=0;
	cin>>n;
	sum+=n*5;
	vector<int> vec(n);
	for(int i=0;i<n;++i) {
		cin>>vec[i];
	}
	sum+=6*vec[0];
	for(int i=1;i<n;++i) {
		if(vec[i] > vec[i-1]) {
			int temp=vec[i]-vec[i-1];
			sum+=temp*6;
		} else {
			int temp=vec[i-1]-vec[i];
			sum+=temp*4;
		}
	}
	cout<<sum;
	return 0;
}
