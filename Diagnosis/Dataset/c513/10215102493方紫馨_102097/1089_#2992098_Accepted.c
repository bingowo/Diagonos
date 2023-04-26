#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		long long int a,ret = 1,p;
		int b,n;
		scanf("%lld%d%d",&a,&b,&n);
		p = (int)pow(10,n);
		for(int k=0;k<b;k++){
			ret = (ret * a)%p;
		}
		printf("case #%d:\n",i);
		char num[10];
		sprintf(num,"%lld",ret);
		for(int i=0;i<n-strlen(num);i++)
			printf("0");
		printf("%s\n",num);
	}	
	return 0;
}