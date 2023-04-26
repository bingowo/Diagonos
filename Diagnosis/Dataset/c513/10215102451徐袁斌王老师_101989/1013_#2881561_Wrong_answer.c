#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int x=0,y=1,j=0,sum=0;
	sum=0;
	char b[10000];
	scanf("%s",b);
	int c=strlen(b);
	while(j<c&&b[j]!='.')
	{	if(b[j]=='2')
		{
			b[j]='/';
		}
		j++;
	}
	for(int i=0;i<j;i++)
	{
		sum=sum+(b[i]-48)*pow(3,j-i-1);
	}
	if(b[j]=='.')
	{
		j++;
		while(b[j]!='\0')
		{
			if(b[j]=='2')
			{
				b[j]='/';
			}
			y=y*3;
			x=x*3+(b[j]-48);
			j++;
		}
		if(x<0&&sum>0) {sum--;x=y+x;}
		if(x>0&&sum<0) {sum++;x=y-x;}
		for(int k=x;k>=1;k--)
		{
			if((x%k==0)&&(y%k==0))
			{
				x=x/k;
				y=y/k;
			}
		}
	}
	if(x==0&&sum!=0) printf("%d",sum);
	if(x!=0&&sum==0) printf("%d %d",x,y);

	
	

	
	return 0;
	
	
 } 