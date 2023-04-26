#include <stdio.h>
#include<stdlib.h> 
#include<string.h>

int main()
{ 
	int T,N,i,j,ret=0,a[33];
	char s[100];
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%s",&s);
		ret=0;
//		if(s[strlen(s)-1]=='1') ret=1;
//		else if(s[strlen(s)-1]=='0') ret=0;
//		else if(s[strlen(s)-1]=='-') ret=-1;
		for(j = 0;j<strlen(s);j++)
		{
			if (s[j]=='1') ret=ret*3+1;
			else if(s[j]=='-') ret=ret*3-1;
			else if (s[j]=='0') ret=ret*3+0;
		}
		printf("case #%d:\n",i);
		printf("%d\n",ret);
	} 
    return 0;
}
