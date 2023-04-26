#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
double m[27];
int cmp(const void*a,const void*b)
{
	char q1,q2;
	q1=*(char*)a;
	q2=*(char*)b;
	int p1,p2;
	if(q1>='a'&&q1<='z') p1=q1-'a';
	else p1=q1-'A';
	if(q2>='a'&&q2<='z') p2=q2-'a';
	else p2=q2-'A';
	if(m[p2]>m[p1]) return 1;
	else if(fabs(m[p1]-m[p2])<1e-8)
		{
		
			if(p1==p2) return q1-q2;
			else return p1-p2;
		}
	else return -1;
}


int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		
		int j=0;
		for(j;j<26;j++) scanf("%lf",&m[j]);
		char str[101];
		scanf("%s",str);
		int len=strlen(str);
		qsort(str,len,sizeof(str[0]),cmp);
		printf("case #%d:\n",i);
		printf("%s\n",str);
		 
	}
	return 0;
}