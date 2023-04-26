#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<string.h>
typedef struct{
	int year;
	int m;
	char mon[25];
	int day;
}node;
int cmp(const void*a,const void*b)
{
	
node p1=*((node*)a);
node p2=*((node*)b);
if(p1.year!=p2.year)
{
	return p1.year-p2.year;
}
else if(p1.m!=p2.m)
return p1.m-p2.m;
else return p1.day-p2.day;


} 
int main()
{
	int T;
	char a[][25]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac","ceh", "mac","kankin", "muan", "pax", "koyab", "cumhu","uayet"};
	scanf("%d",&T);
	
	for(int i=0;i<T;i++)
	{node t[10005]={0};
		int n;
		char d[5];
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
		    
			scanf("%s%s%d",d,t[j].mon,&t[j].year);
			int k;
			for(k=0;k<19;k++)
			if(strcmp(a[k],t[j].mon)==0)break;
			t[j].m=k;
			int sum=0;
			k=0;
			while(d[k]!='.')
			{sum=sum*10+d[k]-'0';}
			t[j].day=sum;
			
		}
		
		qsort(t,n,sizeof(t[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++)
		{
			printf("%s %s %d\n",t[j].day,t[j].mon,t[j].year);
		}
		
		
		
		
	}
	return 0; 
} 