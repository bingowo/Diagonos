#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int T,len,times=0;
	char input[20];
	long long int weight,res;
	scanf("%d",&T);
	while(T--){
		scanf("%s",input);
		len=strlen(input);
		weight=1;
		res=0;
		for (int i=len-1;i>=0;i--){
			if (input[i]=='-')
				res=res+weight*(-1);
			if (input[i]=='1')
				res=res+weight*1;
			weight=weight*3;
		}
		printf("case #%d:\n%lld\n",times,res);
		times+=1;
	}
}