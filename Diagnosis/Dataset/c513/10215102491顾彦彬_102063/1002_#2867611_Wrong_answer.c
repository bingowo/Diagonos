#include<stdio.h>
#include<string.h>
main()
{
	char table[]="1023456789",ans[100000];
	long long int a[123],T,m=0,res,count,weight,times;
	char input[100000]={'\0'};
	for (int i=0;i<=122;i++)
		a[i]=-1;
	scanf ("%lld",&T);
	for (int j=0;j<T;j++){
		scanf("%c",&input);
		m=0;
		res=0;
		count=0;
		for (int k=0;k<strlen(input);k++)
		{
			if (a['input[k]']!=-1)
				{
					a['input[k]']=table[m];
					count+=1;
				}
			ans[k]=a['input[k]'];
		}
		weight=1;
		times=1;
		for (int n=strlen(ans)-1;n>=0;n--)
		{
			for (int j=1;j<times;j++)
					weight=weight*count;
			res=res+ans[n]*weight;
			times+=1;
		}
		printf("case #%d:\n",j);
		printf("%lld\n",res);
	}
}