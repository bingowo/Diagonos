#include<stdio.h>
#include<string.h>
int main()
{
	char oct[52],de[148];	
	int number,j,i,d,temp,t,m;
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
		scanf("%s",oct);
		number=0;memset(de,0,sizeof(de));
		for(i=strlen(oct)-1;i>1;i--)
		{
			d=oct[i]-'0';
			j=0;
			while(d!=0||j<number)
			{
				if(j<number)temp=d*10+de[j]-'0';
				else temp=d*10;
				de[j++]=temp/8+'0';
				d=temp%8;
			}
			number=j;
		}
		de[number]='\0';
		printf("case #%d:\n0.%s\n",m,de);
	}
} 