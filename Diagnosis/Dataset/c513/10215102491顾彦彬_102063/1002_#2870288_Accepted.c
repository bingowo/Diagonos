#include<stdio.h>
#include<string.h>
main()
{
	
	long long int a[123],m=0,res,count,weight;
	int T,times,table[60];
	char input[60]={'\0'};
	table[0]=1;
	table[1]=0;
	for (int l=2;l<=59;l++)
		table[l]=l;
	scanf ("%d",&T);
	for (int j=0;j<T;j++)
	{
		int ans[60];
		for (int i=0;i<=122;i++)
				a[i]=-1;
		scanf("%s",input);
		m=0;
		res=0;
		count=0;
		for (int k=0;k<strlen(input);k++)
		{
			if (a[input[k]]==-1)
				{
					a[input[k]]=table[m];
					m++; 
					count+=1;
				}
			ans[k]=a[input[k]];
		}
		/*for(int k=0;k<strlen(input);k++){
			printf("%d ",ans[k]);
		}*/
		times=1;
		weight=1;
		if(count==1) count=2;
		for (int n=strlen(input)-1;n>=0;n--)
		{
			res=res+ans[n]*weight;
			weight=weight*count;
		}
		printf("case #%d:\n",j);
		printf("%lld\n",res);
	}
}