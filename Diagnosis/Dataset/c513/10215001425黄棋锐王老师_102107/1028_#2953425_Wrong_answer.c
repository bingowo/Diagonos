#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void xiao(int*d,int n,char p)
{
	int b[1002]={0};
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		b[d[i]]+=1;
		j++;
	} 
	if(p=='A')
	{
		for(i=0;i<1001&&j>0;i++)
		{
			if(b[i])
			 {
				printf("%d%c",i,((j>1)?' ':'\n'));
				j--;
			 }
		}
	}
	else if(p=='D')
	{
		for(i=1001;i>=0&&j>0;i--)
		{
			if(b[i])
			 {
				printf("%d%c",i,((j>1)?' ':'\n'));
				j--;
			 }
		}
	}
}
 int main()
 {  char c,p;
 	scanf("%c",&p);
 	int d[101];
 	int n=0,j;
 	while((c=getchar())==' '||(c=getchar())=='\n')
	 scanf("%d",&d[n++]);
	 xiao(d,n,p);
		return 0;
}