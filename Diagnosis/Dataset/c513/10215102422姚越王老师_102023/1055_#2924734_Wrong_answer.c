#include<stdio.h>
#include<string.h>
int repeat(int ix,int jx,const char* str)
{
	int i=ix,j=jx,k,p;
	for(k=i;k<=j;k++)
	{
		for(p=k+1;p<=j;p++)
			if(str[p]==str[k])return 0;
	}
	return 1;
}
int main()
{
	char str[1000001];
	scanf("%s",str);
	int i,j,k,len,max=-1,begin,end;
	for(i=0;i<strlen(str);i++)
	{
		j=i+1;
		while(repeat(i,j,str)&&j<strlen(str))j++;
		len=j-i;
		if(len>max)
		{
			begin=i;
			end=j-1;
			max=len;
		}
		i=j-1;
	}
	for(k=begin;k<=end;k++)printf("%c",str[k]);
	return 0;
}