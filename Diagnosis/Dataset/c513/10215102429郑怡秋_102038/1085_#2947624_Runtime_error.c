#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int a[501],b[501];
	char c;
	int i=0,j=0;
	
	while((c=getchar())!=' ') a[i++]=c-'0';
	while((c=getchar())!='\n') b[j++]=c-'0';
	while(c!=EOF)
	{
	int res=0;
	int carry=0;
	for(int k=1;k<=i;k++)
	{	
		int l=b[j-k];
		if(j-k<0) l=0;
		int n=a[i-k]-l+carry;
		if(n<0)
		{
			n+=10;
			a[i-k]=n;
			carry=-1;
		}
		else
		{
			a[i-k]=n;
			carry=0;
		}
	}
	int s=0;
	while(a[s++]==0);
	for(int k=s-1;k<i;k++) printf("%d",a[k]);
	printf("\n"); 
	while(i) a[i--]=0;
	while(j) b[j--]=0;
	while((c=getchar())!=' ') a[i++]=c-'0';
	while((c=getchar())!='\n') b[j++]=c-'0';
	}
	return 0;
}