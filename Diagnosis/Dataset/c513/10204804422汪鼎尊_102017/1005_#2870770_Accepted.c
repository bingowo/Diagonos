#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int d[200];

void fmt(int* num)
{
	int i=199;
	while(*(num+i)==0)i--;
	for(;i>=1;i--)if(*(num+i)>=10)
	{
		*(num+i-1)+=(*(num+i))/10;
		(*(num+i))=(*(num+i))%10;
	}
}

int add(int* dest,int* num,int multiplier)
{
	int i;
	for(i=199;i>=0;i--)
	{
		*(dest+i)=*(dest+i)+(*(num+i))*multiplier;
	}
	fmt(dest);
	for(i=199;i>=0;i--)if(dest[i]!=0)return i+1;
}

void div8()
{
	int i;
	for(i=199;i>=3;i--)d[i]=d[i-3];
	memset(d,0,3*sizeof(int));
	add(d,d,124);
	fmt(d);
}

int main()
{
	char input[54];
	int result[200];
	int i;
	int cases,c;
	int len;
	scanf("%d",&cases);
	for(c=0;c<cases;c++)
	{
		memset(result,0,200*sizeof(int));
		memset(d,0,200*sizeof(int));
		d[0]=1;d[1]=2;d[2]=5;
		scanf("%s",&input);
		for(i=2;input[i]!='\0';i++)
		{
			if(input[i]!='0')len=add(result,d,input[i]-'0');
			div8();
		}
		printf("case #%d:\n0.",c);
		for(i=0;i<len;i++)printf("%d",result[i]);
		if(c!=cases-1)putchar('\n');
	}
	return 0;
}