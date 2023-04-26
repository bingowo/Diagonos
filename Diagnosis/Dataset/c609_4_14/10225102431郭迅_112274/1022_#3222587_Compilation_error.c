#include<stdio.h>
#include<stdlib.h>
#include<cctype> 
#define N 1000000
int strcmp(const void*a,const void*b)
{
	char *aa=(char*)a;
	char *bb=(char*)b;
	int i,j,t=0;
	for(i=0;*aa!='@';i++);
	for(j=0;*bb!='@';j++);
	aa+=i;bb+=j;
	while(*aa&&*bb){
		if (*aa > *bb)
		{
			return 1;
		}
		else if (*aa < *bb)
		{
			return -1;
		}
		else //如果两个元素相等，进入下一个继续比较
		{
			++aa;
			++bb;
		}
}//长度不同
	if(*aa){return 1;
	} 
	else if(*bb){return -1;
	}
	else 
	{
		aa=(char*)a;bb=(char*)b;
		while(*aa!='@'&&*bb!='@'){
		if (*aa > *bb)
		{
			return -1;
		}
		else if (*aa < *bb)
		{
			return 1;
		}
		else //如果两个元素相等，进入下一个继续比较
		{
			++aa;
			++bb;
		}
		}
		if(*aa=='@'){return 1;
		}
		else return -1;
	}
}
int main()
{
	int n;scanf("%d",&n);
	char s[n][N];
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);		
	}
	qsort(s,n,N,strcmp);
	for(int i=0;i<n;i++){
		printf("%s\n",s[i]);
	}
}