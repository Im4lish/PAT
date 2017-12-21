#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	double sum=0;
	int cnt=0;
	char a[50];
	char b[50];
	int n;
	scanf("%d",&n); 
	for(int i=0;i<n;++i) {
		double temp;
		scanf("%s",a);
		sscanf(a,"%lf",&temp);
		sprintf(b,"%.2lf",temp);
		int flag=0;
		for(int j=0;j<strlen(a);++j) {
			if(a[j] != b[j]) {
				flag=1;
				break;
			}
		}
		if(flag == 1 || temp < -1000 || temp > 1000) {
			printf("ERROR: %s is not a legal number\n",a);
		} else {
			sum+=temp;
			cnt++;
		}
	}
	if(cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(cnt > 1) {
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
	return 0;
}
