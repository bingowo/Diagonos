#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
double p[27];
int cmp(const void *a,const void *b); 

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++)
	{
		int j;
		for (j=0;j<26;j++) scanf("%lf",&p[i]);
		char str[101];
		scanf("%s",str);
		qsort(str,strlen(str),sizeof(str[0]),cmp);
		printf("case#%d:\n",i);
		printf("%s\n",str);
	}
	return 0;
}

int cmp(const void *a,const void *b)
{
    char ch1,ch2;  //ch1,ch2为待比较的字母
    int p1,p2;         //p1,p2为ch1,ch2在字母顺序表中的序号
    ch1=*((char *)a);
    ch2=*((char *)b);
    if(p[tolower(ch1)-97]>p[tolower(ch2)-97])
    {
    	return -1;
	}
	else if(p[tolower(ch1)-97]==p[tolower(ch2)-97])
	{
		if(ch1<ch2) return -1;
		else return 1;
	}
	else return 1;
}