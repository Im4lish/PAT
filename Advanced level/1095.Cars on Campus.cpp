#include<iostream> 
#include<vector>
#include<string>
#include<cstdio>
#include <algorithm>
using namespace std;

const int maxn = 20000;

struct Car {
	string plate;
	int time;
	int flag;
};

int num[24 * 60 * 60] = { 0 };
vector<Car> origin;
vector<Car> process;
int maxTime = 0;
vector<string> maxPlate;

bool cmp(Car a, Car b) {
	if (a.plate != b.plate) {
		return a.plate < b.plate;
	}
	else {
		return a.time<b.time;
	}
}



int main() {
	int n;
	int k;
	cin >> n >> k;
	int hh;
	int mm;
	int ss;
	string f;
	string in = "in";
	string out = "out";
	Car temp;
	for (int i = 0; i<n; ++i) {
		cin >> temp.plate;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		cin >> f;
		temp.time = hh * 3600 + mm * 60 + ss;
		if (f == in) {
			temp.flag = 1;
		}
		else if (f == out) {
			temp.flag = -1;
		}
		origin.push_back(temp);
	}

	sort(origin.begin(), origin.end(), cmp);



	for (int i = 0; i<origin.size(); ++i) {
		if (origin[i].plate == origin[i + 1].plate && origin[i].flag == 1 && origin[i+1].flag == -1) {
			process.push_back(origin[i]);
			process.push_back(origin[i + 1]);
		}
	}



	for (int i = 0; i<process.size(); i = i + 2) {
		num[process[i].time]++;
		num[process[i + 1].time]--;
		int temp = process[i + 1].time - process[i].time;
		if (temp>maxTime) {
			maxTime = temp;
			maxPlate.clear();
			maxPlate.push_back(process[i].plate);
		}
		else if (temp == maxTime) {
			maxPlate.push_back(process[i].plate);
		}
	}

	for (int i = 1; i<24 * 60 * 60; ++i) {
		num[i] += num[i - 1];
	}

	for (int i = 0; i<k; ++i) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		printf("%d\n", num[hh*3600+mm*60+ss]);
	}
	for (int i = 0; i<maxPlate.size() - 1; ++i) {
		cout << maxPlate[i] << " ";
	}
	printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60 );
	
	return 0;
}


/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#define maxn 10050
using namespace std;
struct node2         //??????
{
    string id;        //  ??
    int state;        //  1:in  0:out
    int sum;          
    int in_time;     
    int loc;          // ???in?????
} ID[maxn];
     
struct node          //??????
{
    int time;
    string id;
    int state;
    int flag;        // ???????
} s[maxn];
     
map<string,int>q;
set<string>w;
     
int cmp(node a,node b)
{
    return a.time<b.time;
}
     
int main()
{
//    freopen("in.txt","r",stdin);
    int n,m;
    int query[maxn*8];
    string str1,str2;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        cin>>s[i].id>>str1>>str2;
        s[i].flag=0;
        s[i].time=((str1[0]-'0')*10+str1[1]-'0')*3600+((str1[3]-'0')*10+str1[4]-'0')*60+((str1[6]-'0')*10+str1[7]-'0');
        s[i].state=str2.compare("in")==0?1:0;
    }
     
    for(int i=1; i<=m; i++)
    {
        cin>>str1;
        query[i]=((str1[0]-'0')*10+str1[1]-'0')*3600+((str1[3]-'0')*10+str1[4]-'0')*60+((str1[6]-'0')*10+str1[7]-'0');
    }
     
    sort(s+1,s+1+n,cmp);
     
    int num=1,Que=1,ss=0,d;
    int ans=0;
    for(int i=1; i<=n; i++)         //???????
    {
        str1=s[i].id;
        if(q[str1]==0)                            //????????
        {
            ID[num]= {s[i].id,s[i].state,0,s[i].time,i};
            q[str1]=num++;
        }
        else
        {
            d=q[str1];
            if(ID[d].state==1&&s[i].state==1)      //??in????? ???in?????
            {
                s[ID[d].loc].flag=1;
                ID[d].loc=i;
            }
            else if(ID[d].state==1&&s[i].state==0) //??
                ID[d].state=0;
            else if(ID[d].state==0&&s[i].state==1)   //????
            {
                ID[d].state=1;
                ID[d].loc=i;
            }
            else if(ID[d].state==0&&s[i].state==0)  //??out?????
                s[i].flag=1;
        }
    }
    for(int i=1;i<num;i++)
    {
        if(ID[i].state==1)         //????? ???
        {
            s[ID[i].loc].flag=1;
            ID[i].state=0;
        }
    }
    for(int i=1; i<=n; i++)         //??????
    {
        if(s[i].flag)
            continue;
        while(Que<m+1&&query[Que]<s[i].time)  //  while ??
        {
            Que++;
            printf("%d\n",ss);
        }
        str1=s[i].id;
        d=q[str1];
        if(ID[d].state==1&&s[i].state==0) //?? ??
        {
            ss--;
            ID[d].state=0;
            ID[d].sum+=s[i].time-ID[d].in_time;
            if(ID[d].sum>ans){
                ans=ID[d].sum;
                w.clear();
                w.insert(ID[d].id);
            }
            else if(ID[d].sum==ans)
                w.insert(ID[d].id);
     
        }
        else if(ID[d].state==0&&s[i].state==1)   //????
        {
            ss++;
            ID[d].state=1;
            ID[d].in_time=s[i].time;
        }
     
    }
    while(Que<m+1)
    {
        printf("%d\n",ss);
        Que++;
    }
    set<string>::iterator ii;
    for(ii=w.begin();ii!=w.end();ii++)
        cout<<*ii<<" ";
    printf("%02d:%02d:%02d\n",ans/3600,ans%3600/60,ans%60);
   return 0;
}
*/
