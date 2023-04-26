#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double array[128];
int cmp(const void* a,const void* b)
{
	char *p1=(char*)a,*p2=(char*)b;
	if(array[*p1]>array[*p2])return -1;
	else if(array[*p1]<array[*p2])return 1;
	else if(array[*p1]==array[*p2])
	{
	    if(*p1==*p2+32||*p2==*p1+32)
	    {
	        if(*p1>*p2)return -1;
	        else return 1;
	    }
	    else
	    {
	        if(*p1>='A'&&*p1<='Z')*p1+=32;
	        if(*p2>='A'&&*p2<='Z')*p2+=32;
	        return *p1-*p2;
	    }
	    
	}
	
}
int main()
{
	int T,i,j;scanf("%d",&T);
	double t;char s[110];
	for(i=0;i<T;i++)
	{
		for(j='A';j<='Z';j++)
		{
			scanf("%lf",&t);
			array[j]=t;array[j+32]=t;
		}
		scanf("%s",s);
		qsort(s,strlen(s),sizeof(char),cmp);
		printf("case #%d:\n%s\n",i,s);
	}
	return 0;
}