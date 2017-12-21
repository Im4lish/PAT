#include<iostream>
#include<vector>
using namespace std;

int minboy=101;
int maxgirl=-1;
int minboyid=-1;
int maxgirlid=-1;
int n;

struct Person {
	string name;
	char sex;
	string classid;
	int grade;
};

int main() {
	cin>>n;

	vector<Person> vec(n);
	for(int i=0;i<n;++i) {
		cin>>vec[i].name>>vec[i].sex>>vec[i].classid>>vec[i].grade;
		
		if(vec[i].sex == 'M') {
			if(vec[i].grade < minboy) {
				minboy=vec[i].grade;
				minboyid=i;
			}
		} else if(vec[i].sex == 'F') {
			if(vec[i].grade > maxgirl) {
				maxgirl=vec[i].grade;
				maxgirlid=i;
			}
		}
	}	
	
	bool flag=true;
	if(maxgirlid == -1) {
		cout<<"Absent"<<endl;
		flag=false;
	} else {
		cout<<vec[maxgirlid].name<<" "<<vec[maxgirlid].classid<<endl;
	}
	if(minboyid == -1) {
		cout<<"Absent"<<endl;
		flag=false;
	} else {
		cout<<vec[minboyid].name<<" "<<vec[minboyid].classid<<endl;
	}
	if(flag == false) {
		cout<<"NA"<<endl;
	} else {
		cout<<maxgirl-minboy<<endl;
	}
	return 0;
}
