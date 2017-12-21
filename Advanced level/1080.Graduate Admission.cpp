#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxapp=40000;
const int maxsch=100;

int n;
int m;
int k;

struct Stu {
	int id;
	int grade;
	int gi;
	int ge;
	int rank;
	vector<int> school;
};

struct Sch {
	int maxnum;
	int nownum;
	vector<int> student;
	int lastRank;
};

vector<Stu> stu(maxapp);
vector<Sch> sch(maxsch);

bool cmp(Stu a,Stu b) {
    if(a.grade != b.grade) {
        return a.grade > b.grade;
    } else {
        return a.ge > b.ge;
    }
}

int main() {
	cin>>n>>m>>k;
	stu.resize(n);
	sch.resize(m);
	for(int i=0;i<m;++i) {
		int num;
		cin>>num;
		sch[i].maxnum=num;
		sch[i].nownum=0;
		sch[i].lastRank=-1;
	}
	for(int i=0;i<n;++i) {
		int ge;
		int gi;
		int s;
		
		cin>>ge>>gi;
		stu[i].gi =gi;
		stu[i].ge=ge;
		stu[i].grade=gi+ge;
		stu[i].id=i;
		for(int j=0;j<k;++j) {
			cin>>s;
			stu[i].school.push_back(s);
		}
	}
	
	sort(stu.begin(),stu.end(),cmp);
	
	stu[0].rank=1;
	for(int i=1;i<n;++i) {
		if(stu[i].grade==stu[i-1].grade && stu[i].ge==stu[i-1].ge) {
			stu[i].rank=stu[i-1].rank;
		} else {
			stu[i].rank=stu[i-1].rank+1;
		}
	}
	
	for(int i=0;i<n;++i) {
		Stu nowstu=stu[i];
		int nowrank=nowstu.rank;
		int nowid=nowstu.id;
		for(int j=0;j<k;++j) {
			int nowschid=nowstu.school[j];
			if(sch[nowschid].nownum < sch[nowschid].maxnum || sch[nowschid].lastRank==nowrank) {
				sch[nowschid].nownum++;
				sch[nowschid].lastRank=nowrank;
				sch[nowschid].student.push_back(nowid);
				break;
			}
		}
	}
	
	for(int i=0;i<m;++i) {
		sort(sch[i].student.begin(),sch[i].student.end());
		for(int j=0;j<sch[i].student.size();++j) {
			if(j!=0) {
				cout<<" ";
			}
			cout<<sch[i].student[j];
		}
		cout<<endl;
	}
}
 
