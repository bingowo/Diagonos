#include <stdio.h>
#include <string.h>
int main()
{
	char s[1001];
	scanf("%s",s);
	int len=strlen(s);
	int count[10000]={0};
	count[0]=1;
	int i=0,j=0,k=0,carry=0;
	if(len==1) printf("1");
	else{
	
		for(i;i<len;i++)
		{
	//	printf("carry=%d\n",carry);
			if(i==0) 
			{
				if(s[i]==s[i+1]) count[j++]*=1;
				else count[j++]*=2;
			}
			else if(i==len-1)
			{
			//printf("carry=%d\n",carry);
				int m2;
 				if(s[i]!=s[i-1]) m2=2;
 				else m2=1;
				for(k=0;k<=j;k++)
 				{
 				//printf("c2=carry=%d\n",carry);
					count[k]=count[k]*m2+carry;
				//printf("%d\n",count[k]);
 					carry=count[k]/10;
 					count[k]%=10;
 				//printf("carry=%d\n",carry);
 				
				}
				j=k+1;
			
 			}
 			else
 			{
 				int m;
 				if(s[i]!=s[i-1]&&s[i]!=s[i+1]) m=3;
 				else if(s[i]==s[i-1]&&s[i]==s[i+1]) m=1;
 				else m=2;
				for(k=0;k<=j;k++)
 				{
 					count[k]=count[k]*m+carry;
 					carry=count[k]/10;
 					count[k]%=10;
 				
 	
				}
				j=k+1;
			}
 		//printf("%d\n",count[0]);
		
		}
		int e=j;
		for(e;count[e]==0;e--);
		for(e;e>=0;e--) printf("%d",count[e]);
	}
	printf("\n");
	return 0;
}