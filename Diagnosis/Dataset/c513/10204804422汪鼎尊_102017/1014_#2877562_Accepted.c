#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void pr(int i)
{
	if(i==2)putchar('1');
	else if(i==1)putchar('0');
	else if(i==0)putchar('2');
}

int main()
{
	int up,down,pos=0,i,j=0,z=0;
	int result[100];
	for(i=0;i<100;i++)result[i]=1;
	scanf("%d %d",&up,&down);
	if(up==0)
	{
		printf("0");
		return 0;
	}
	if(up<=down/2)printf("0.");
	while(up>0)
	{
		result[pos++]=(up%3)+1;
		up/=3;
	}
	for(i=0;i<pos;i++)if(result[i]>=3)
	{
		result[i]-=3;
		result[i+1]++;
	}
	if(result[pos]==2)pos++;
	if(down!=1)while(down>=3)
	{
		down/=3;
		j++;
	}
	else j=-1;
	if(pos<j)pos=j;
	while(result[z]==1&&z<j)z++;
	//printf("%d %d %d ",pos,j,z);
	for(i=pos-1;i>=z;i--)
	{
		pr(result[i]);
		if(i==j&&z<j)putchar('.');
	}
	return 0;
}