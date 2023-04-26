#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{int d;int m;int y;} date;
//pop 1,no 2,zip 3,zotz 4,tzec 5,xul 6,yoxkin 7,mol 8,chen 9,yax 10,zac 11,ceh 12
//mac 13,kankin 14,muan 15,pax 16,koyab 17,cumhu 18,uayet 19
int cmp(const void* a,const void* b)
{
	date *p1=(date*)a,*p2=(date*)b;
	if(p1->y!=p2->y)return p1->y-p2->y;
	else
	{
		if(p1->m!=p2->m)return p1->m-p2->m;
		else
		{
			return p1->d-p2->d; 
		}
	}
}
int main()
{
	int T,N,i,j;scanf("%d",&T);
	char t[10];
	for(i=0;i<T;i++)
	{
		scanf("%d\n",&N);
		date a[N];
		for(j=0;j<N;j++)
		{
			scanf("%s",t);
			t[strlen(t)-1]=0;
			a[j].d=atoi(t);
			scanf("%s",t);
			if(strcmp(t,"pop")==0)a[j].m=1;
			if(strcmp(t,"no")==0)a[j].m=2;
			if(strcmp(t,"zip")==0)a[j].m=3;
			if(strcmp(t,"zotz")==0)a[j].m=4;
			if(strcmp(t,"tzec")==0)a[j].m=5;
			if(strcmp(t,"xul")==0)a[j].m=6;
			if(strcmp(t,"yoxkin")==0)a[j].m=7;
			if(strcmp(t,"mol")==0)a[j].m=8;
			if(strcmp(t,"chen")==0)a[j].m=9;
			if(strcmp(t,"yax")==0)a[j].m=10;
			if(strcmp(t,"zac")==0)a[j].m=11;
			if(strcmp(t,"ceh")==0)a[j].m=12;
			if(strcmp(t,"mac")==0)a[j].m=13;
			if(strcmp(t,"kankin")==0)a[j].m=14;
			if(strcmp(t,"muan")==0)a[j].m=15;
			if(strcmp(t,"pax")==0)a[j].m=16;
			if(strcmp(t,"koyab")==0)a[j].m=17;
			if(strcmp(t,"cumhu")==0)a[j].m=18;
			if(strcmp(t,"uayet")==0)a[j].m=19;
			scanf("%d",&a[j].y);
		}
		qsort(a,N,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<N;j++)
		{
			printf("%d. ",a[j].d);
			if(a[j].m==1)printf("pop ");
			if(a[j].m==2)printf("no ");
			if(a[j].m==3)printf("zip ");
			if(a[j].m==4)printf("zotz ");
			if(a[j].m==5)printf("tzec ");
			if(a[j].m==6)printf("xul ");
			if(a[j].m==7)printf("yoxkin ");
			if(a[j].m==8)printf("mol ");
			if(a[j].m==9)printf("chen ");
			if(a[j].m==10)printf("yax ");
			if(a[j].m==11)printf("zac ");
			if(a[j].m==12)printf("ceh ");
			if(a[j].m==13)printf("mac ");
			if(a[j].m==14)printf("kankin ");
			if(a[j].m==15)printf("muan ");
			if(a[j].m==16)printf("pax ");
			if(a[j].m==17)printf("koyab ");
			if(a[j].m==18)printf("cumhu ");
			if(a[j].m==19)printf("uayet ");
			printf("%d\n",a[j].y);
		}
		//pop 1,no 2,zip 3,zotz 4,tzec 5,xul 6,yoxkin 7,mol 8,chen 9,yax 10,zac 11,ceh 12
//mac 13,kankin 14,muan 15,pax 16,koyab 17,cumhu 18,uayet 19
	}
	return 0;
	
}