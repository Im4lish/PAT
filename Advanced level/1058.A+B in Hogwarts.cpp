#include<iostream>
#include<cstdio>
struct Node {
	int Galleon=0;
	int Sickle=0;
	int Knut=0;
};

Node a;
Node b;
Node c;

int main() {
	scanf("%d.%d.%d",&a.Galleon,&a.Sickle,&a.Knut);
	scanf("%d.%d.%d",&b.Galleon,&b.Sickle,&b.Knut);
	c.Knut=a.Knut+b.Knut;
	if(c.Knut>=29) {
		c.Knut=c.Knut-29;
		c.Sickle=1;
	}
	c.Sickle=c.Sickle+a.Sickle+b.Sickle;
	if(c.Sickle>=17) {
		c.Sickle=c.Sickle-17;
		c.Galleon=1;
	}
	c.Galleon=c.Galleon+a.Galleon+b.Galleon;
	printf("%d.%d.%d",c.Galleon,c.Sickle,c.Knut);
	return 0;
}
