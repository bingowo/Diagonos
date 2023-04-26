#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
	int n;
	char s[21];
};
int cmp1(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	return strcmp(c.s ,d.s);
}
int cmp2(const void*a,const void*b)
{
	struct data c=*(struct data*)a;
	struct data d=*(struct data*)b;
	if(c.n < d.n )
	{
		return -1;
	}
	if(c.n >d.n )
	{
		return 1;
	}
	else{
		return strcmp(c.s ,d.s);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	struct data DNA[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",DNA[i].s );
		DNA[i].n =-1;
	}
	qsort(DNA,n,sizeof(DNA[0]),cmp1);//先按字典序排序
/*	printf("cmp1:\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",DNA[i].s );
	}*/
	struct data ans[n];
	i=0;
	int k=0;
	while(i<n)//去重，找n 
	{
		int cnt=0;
		int j=i;
		while(strcmp(DNA[i].s,DNA[i+1].s )==0)
		{
			cnt++;
			i++;
		}
		strcpy(ans[k].s,DNA[j].s);
		ans[k].n =cnt;
		k++;
		i++;
	}
/*	printf("t2:\n");
	for(i=0;i<k;i++)
	{
		printf("%s\n",ans[i].s );
	}*/
	qsort(ans,k,sizeof(ans[0]),cmp2);//按照n升序
	//printf("cmp2:\n");
	for(i=0;i<k;i++)
	{
		printf("%s\n",ans[i].s );
	 } 
	return 0;
 } 