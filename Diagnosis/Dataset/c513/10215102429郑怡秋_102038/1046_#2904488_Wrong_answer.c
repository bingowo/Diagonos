#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	int t;
	scanf("%d\n",&t);
	for(int i=0;i<t;i++)
	{
		char A[120][120];
		int j=0;
		do{
			scanf("%s",A[j++]);
		}while(getchar()!='\n');
		int ans=0;
		for(int k=0;k<j;k++)
		{
			//printf("%s\n",A[k]);
			if(strcmp(A[k],"the")==0||strcmp(A[k],"a")==0||strcmp(A[k],"an")==0||strcmp(A[k],"of")==0||strcmp(A[k],"for")==0||strcmp(A[k],"and")==0)
			{
				ans+=0;
			}
			else if(strcmp(A[k],"THE")==0||strcmp(A[k],"A")==0||strcmp(A[k],"AN")==0||strcmp(A[k],"OF")==0||strcmp(A[k],"FOR")==0||strcmp(A[k],"AND")==0)
			{
				ans+=0;
			}
			else ans++; 
		}
		printf("case #%d:\n",i);
		printf("%d\n",ans);
		
	}
	return 0;
}