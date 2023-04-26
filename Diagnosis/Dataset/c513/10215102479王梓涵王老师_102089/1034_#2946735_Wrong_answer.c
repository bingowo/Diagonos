#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
double p[26];
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
		char str[200];
		scanf("%s",str);
		qsort(str,strlen(str),sizeof(str[0]),cmp);
		printf("case #%d:\n",i);
		printf("%s\n",str);
	}
	return 0;
}

int cmp(const void *a,const void *b)
{
    char ch1,ch2;  //ch1,ch2为待比较的字母
    ch1=*((char *)a);
    ch2=*((char *)b);
    if(p[tolower(ch1)-97]>p[tolower(ch2)-97]) return -1;
    else if(p[tolower(ch1)-97]<p[tolower(ch2)-97]) return 1;
	else if(p[tolower(ch1)-97]==p[tolower(ch2)-97])
	{
		if(tolower(ch1)==tolower(ch2)){
			if(ch1>ch2) return -1;
			else return 1;
		}
		else if(tolower(ch1)>tolower(ch2)) return 1;
		else if(tolower(ch1)<tolower(ch2)) return -1;
	}
}