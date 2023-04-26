#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
#define M 1000
int main()
{
	char A[2001]={'0'};
	char c;
	c=getchar();
	if(c>='a'&&c<='z') c-=32;
	A[M]=c;
	int i=0,j=0;
	while((c=getchar())!='\n')
	{
		if(c>='a'&&c<='z') c-=32;//printf("%c\n",c);
		if(c<A[M-i]) j++,A[M+j]=c;
		else if(c>=A[M-i]) i++,A[M-i]=c;
	}
	for(int k=M-i;k<M+j+1;k++) printf("%c",A[k]);
	
	return 0;
}