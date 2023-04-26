#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000000
const char month[19]={pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu,uayet};
typedef struct
{
	int d;
	enum month;
	int y;
}DAY;
int cmp(const void*a,const void*b)
{
	DAY*aa=(DAY*)a;
	DAY*bb=(DAY*)b;
	int y1=aa->y,y2=bb->y;
	int s1=(int)(aa->m),s2=(int)(bb->m);
	int d1=aa->d,d2=bb->d;
	if(y1>y2)return 1;
	else if(y1<y2)return -1;
	else{
		if(s1>s2)return 1;
		else if(s1<s2)return -1;
		else{
			if(d1>d2)return 1;
			else if(d1<d2)return -1;
			else return 0;
		}
	}
}
DAY input(int n)
{
	DAY*p=(DAY*)malloc(sizeof(DAY)*n);
	for(int i=0;i<n;i++){
		scanf("%d.\n",&(p+i)->d);
		scanf("%s\n",&(p+i)->m);
		scanf("%d\n",&(p+i)->y);
	}
	return p; 
}
DAY Sort(DAY *a,int n)
{
    qort(a,n,sizeof(DAY),cmp);
}
int main()
{
	int t,n[t];
	DAY*a=NULL;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",n[i]);
		a=input(n[i]);
		Sort(a,n[i]);
		for(int j=0;j<n[i];j++){
			printf("%d. %s %d",a[j].d,a[j].m,a[j].y);
		}
	}

	}