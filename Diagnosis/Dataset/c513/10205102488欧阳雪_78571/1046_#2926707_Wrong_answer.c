#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		char s[100][100]={0};
		char c;
		char *s1[]={"the","a","an","of","for","and"};
		int j1=0,j2=0,k=0;
		while((c=getchar())!='\n')
		{
			if(c==' '){
				j1++;
				j2=0;
				continue;
			}
			s[j1][j2++]=c;
		}
		int cnt=j1+1;
		//printf("cnt:%d\n",cnt);
		for(k=0;k<=j1;k++)
		{
			for(int t=0;t<6;t++)
			{
			    if(strcmp(s[k],s1[t])==0){
			    	cnt--;
			    	break;
				}	
			}
		}
		printf("case #%d:\n",i);
		printf("%d\n",cnt);
	}
}