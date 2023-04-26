#include<stdio.h>
#include<string.h> 
#include<math.h>

int main()
{
	int t=0,i,j,len,a[123],k;
	long long ans;
	char s[61];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		ans=0;
		scanf("%s",&s);
		len=strlen(s);
		for(j=0;j<123;j++)
		{
			a[j]=-1;
		}
		a[s[len-1]-'0']=1;
		if(len>=2)
			a[s[len-2]-'0']=0;
		k=2;
		for(j=len-3;j>=0;j--)
		{
			if(a[s[j]-'0']==-1)
				a[s[j]-'0']=k++;
		}
		if(len==1)
		{
			printf("case #%d:0\n",i);
			continue;
		}
		else
		{
			for(j=0;j<len;j++)
				ans+=a[s[j]-'0']*pow(len,j);	
		}
		printf("case #%d:%d\n",i,ans);
	}
	return 0;
} 