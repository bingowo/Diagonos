#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct word{
	float fre;
	char letter;
	int ord;
}A[52];//26个字母的大小写 
int cmp(const void*a,const void*b)
{
	struct word c=*(struct word*)a;
	struct word d=*(struct word*)b;
	if(c.fre==d.fre)
	{
		return c.ord-d.ord;
		//if(d.ord>c.ord)return -1;
		//else return 1;
	}
//	if(c.fre>d.fre)return -1;
//	else return 1;
return d.fre-c.fre;
}
int scmp(const void*a,const void*b)
{
	char c1=*(char*)a;
	char c2=*(char*)b;
	int t1,t2;
	for(int i=0;i<52;i++)//按照A[]的标准找到自己的位置 
	{
		if(c1==A[i].letter)
		{
			t1=i;
		}
		if(c2==A[i].letter)
		{
			t2=i;
		}
	}
	return t1-t2;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		int j=0;
		for(j=0;j<52;j+=2)
		{
			float temp;
			scanf("%f",&temp);
			A[j].fre=temp;
			A[j+1].fre=temp;//大小写
			A[j].ord=j;
			A[j+1].ord=j+1;
			A[j].letter=j/2+'a';
			A[j+1].letter=j/2+'A'; 
		}
		qsort(A,52,sizeof(A[0]),cmp);//先把它按照要求排序成标准模样
		char s[101]={0};
		scanf("%s",s);
		qsort(s,strlen(s),sizeof(s[0]),scmp);//对照标准来排序 
		printf("case #%d:\n",i);
		printf("%s\n",s);
	} 
}