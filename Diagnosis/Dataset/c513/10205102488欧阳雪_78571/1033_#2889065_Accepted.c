#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Maya{
	int year;
	char month[10];
	int day;
};
struct Maya M[10000];
char*Month[]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
int cmp(const void*a,const void*b)
{
    struct Maya ma=*(struct Maya*)a;
	struct Maya mb=*(struct Maya*)b;
	if(ma.year!=mb.year ){
		return(ma.year -mb.year );
	}
	else{
		int cnt1=-1,cnt2=-1;
		for(int i=0;i<19;i++)
		{
			if(strcmp(ma.month ,Month[i])==0){
				cnt1=i;
		    }
			if(strcmp(mb.month ,Month[i])==0){
				cnt2=i;
			}
    	}
    	if(cnt1!=cnt2)
    	{
    		return(cnt1-cnt2);
		}
		else{
			return(ma.day -mb.day );
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		char c;
		for(int j=0;j<N;j++)
		{
			scanf("%d",&(M[j].day));
			c=getchar();
			c=getchar();
			int t=0;
			while((c=getchar())!=' ')
			{
				M[j].month[t++]=c;
			}
			M[j].month [t]=0;
			scanf("%d",&M[j].year );
		}
		qsort(M,N,sizeof(M[0]),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<N;k++)
		{
			printf("%d",M[k].day );
			printf(".");
			printf(" ");
			printf("%s",M[k].month );
			printf(" ");
			printf("%d\n",M[k].year ); 
		}
	}
 } 