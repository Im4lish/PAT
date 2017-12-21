#include<iostream>

using namespace std;

int main() {
	string pat;
	cin>>pat;
	int sum=0;
	int countt=0;
	int countp=0;
	for(int i=0;i<pat.size();++i) {
		if(pat[i] == 'T') {		
			countt++;
		}
	}
	for(int i=0;i<pat.size();++i) {
		if(pat[i] == 'P') {		
			countp++;
		}
		if(pat[i] == 'T') {		
			countt--;
		}
		if(pat[i] == 'A') {		
			sum = ( sum+ (countt*countp) %1000000007) %1000000007;
		}
	}
	cout<<sum;
	return 0;
}
