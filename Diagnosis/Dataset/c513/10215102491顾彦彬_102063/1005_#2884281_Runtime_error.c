#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int T,a,i,j=0;
	scanf("%d",&T);
	while(T--)
	{
		a=0;
		i=2;
		char input[55]={},ans[155]={};
		ans[0]='0';
		ans[1]='.';
		scanf("%s",input);
		for (i;i<strlen(input);i++){
			ans[i]=(10*a+input[i]-'0')/8;
			a=(input[i]-'0')%8;	
		}
		while (a!=0){
			ans[i]=(10*a)/8;
			a=(10*a)%8;
			i+=1;
		}
		printf("case #%d:\n",j);
		for (int k=0;k<i;k++)
			printf("%s",ans[k]);
		printf("\n");
	}
}