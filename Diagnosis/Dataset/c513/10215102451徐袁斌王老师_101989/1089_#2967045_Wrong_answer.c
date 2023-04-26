#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t;
	long long int a,b,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		long long int ans=a;b--;
		for(int j=0;j<b;j++)
		{
			ans=ans*a;
			if(ans>(int)pow(10,n))
			{
				ans=ans%((int)pow(10,n));
			}
		}
		printf("case #%d:\n",i);
		while(ans<((int)pow(10,n-1))){printf("0");n--;}
		if(ans!=0) printf("%lld\n",ans);
		else{printf("\n");}
	}
	return 0;
}