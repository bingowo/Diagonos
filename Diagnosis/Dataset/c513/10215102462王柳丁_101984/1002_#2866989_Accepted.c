#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t,i=0,j,r=0,k,b=0;
	int table[122]={-1};
	scanf("%d\n",&t);
	long long int res[100];//储存结果 
	char eve[100];
	for(i=0;i<t;i++)
	{
		j=0,r=0,b=0;
		scanf("%s",eve);
		while(eve[j]!='\0') 
		{
			if(table[eve[j]]!=-2)
			{
				table[eve[j]]=-2;//-2表示已算的数 
				r++;//几进制 
			}
			j++;	//几个数 
		}
		if(r==1)r=2;
		table[eve[0]]=1;
		res[i]=1;
		for(k=1;k<j;k++)
		{
			if(table[eve[k]]==-2){
				table[eve[k]]=b;//第一个为一，二为零，剩下的依次增大，已经不为-2的则是多次出现的
				b=(b?b+1:2);
			}
			res[i]=res[i]*r+table[eve[k]];
		}   
		for(k=0;k<j;k++)
		{
			table[eve[k]]=-1;//还原table 
		}
	}	
	for(i=0;i<t;i++)
	{
		printf("case #%d:\n%lld\n",i,res[i]);	
	}
	return 0;
}