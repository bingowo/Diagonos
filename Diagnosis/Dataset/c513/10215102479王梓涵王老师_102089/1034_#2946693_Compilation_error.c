#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
double p[27];
int cmp(const void *i,const void *j); 

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

int cmp(const void*i,const void*j){
	char *x,*y;
	x=(char*)i;
	y=(char*)j;
	if(a[tolower(*x)-97]>a[tolower(*y)-97]) return -1;
	else if(a[tolower(*x)-97]<a[tolower(*y)-97]) return 1;
	else if(a[tolower(*x)-97]==a[tolower(*y)-97]){     //频率相同的情况 
		if(tolower(*x)==tolower(*y)){
			if(*x>*y) return -1;
			else return 1;
		}
		else if(tolower(*x)>tolower(*y)) return 1;
		else if(tolower(*x)<tolower(*y)) return -1;
	}
}