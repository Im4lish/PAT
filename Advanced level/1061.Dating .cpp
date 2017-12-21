#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main() {
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool flag = false;
	int hour;
	int m;
	for(int i=0;i<(a.size()<b.size() ? a.size():b.size());++i) {
		if(flag == false) {
			if(a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') {
				cout<<week[a[i]-'A']<<" ";
				flag=true;
			} 
		} else {
			if(a[i] == b[i] && a[i] >= '0' && a[i] <='9') {
				hour=a[i]-'0';
				break;
			} else if(a[i] == b[i] && a[i] >= 'A' && a[i] <='N') {
				hour=a[i]-'A'+10;
				break;
			}
		}
	}
	for(int i=0;i<(c.size()<d.size() ? c.size():d.size());++i) {
		if(c[i] == d[i] && isalpha(c[i])) {
			m=i;
			break;
		}
	}
	printf("%02d:%02d",hour,m);
	return 0;
}
