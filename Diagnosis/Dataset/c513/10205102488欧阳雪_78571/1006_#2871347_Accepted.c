#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[1000]={0},c;
		int j=0,ans=0,t=0;
		scanf("%s",s);
		j=strlen(s);
		j=j-1; 
		//printf("%d\n",j);
		int j2=0;
		while(j>=0)
		{
		//	printf("%c ",s[j2]);
			if(s[j2]=='-')t=-1;
			if(s[j2]=='1')t=1; 
			if(s[j2]=='0')t=0;
		//	printf("%d",t); 
			ans=ans+t*pow(3,j);
			j--; 
			j2++; 
		}
		printf("case #%d:\n",i);
		printf("%d\n",ans);
	}
}