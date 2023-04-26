#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	char A[10][100];
	int i=0;
	while(gets(A[i++]));
	int b1=0,b2=0,c1=0,d1=0,d2=0,c2=0;
	for(int j=0;j<i-1;j++)
	{
		for(int l=0;l<strlen(A[j]);l++)
		{
			if(A[j][l]=='"') 
			{
				for(int k=l;k<strlen(A[j]);k++) 
				{
					if(A[j][k]=='/'&&A[j][k+1]=='/') b1=k;
					if(A[j][k]=='/'&&A[j][k+1]=='*') c1=j,d1=k;
					if(A[j][k]=='*'&&A[j][k+1]=='/') c2=j,d2=k+1;
					if(A[j][k]=='"') b2=k;
				}
				if(b1>b2) A[j][l]='\0';
				if(c1<b2) c1=0;
			}
			else if(b1==0&&A[j][l]=='/'&&A[j][l+1]=='/') A[j][l]='\0';
			else if(c1==0&&A[j][l]=='/'&&A[j][l+1]=='*') c1=j,d1=l;
			else if(c1==0&&A[j][l]=='*'&&A[j][l+1]=='/') c2=j,d2=l+1;
		}
	}
	if(c1>0||c2>0) 
	{
		for(int j=0;j<c1-1;j++) printf("%s\n",A[j]);
		for(int j=0;j<d1;j++) printf("%d",A[c1][j]);
		for(int j=d2+1;j<strlen(A[c2]);j++) printf("%c",A[c2][j]);
		printf("\n");
		for(int j=c2+1;j<i-1;j++) printf("%s\n",A[j]); 
	}
	else for(int j=0;j<i-1;j++) printf("%s\n",A[j]);
	return 0;
}