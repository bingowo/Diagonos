#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100001
struct object{
	int a;
	int b;
	int flg;
};
struct object data[MAX];
int main()
{
	char s[200]={0};
	int q;
	scanf("%s",s);
	scanf("%d",&q);
	int x=0,y=0;
	for(int i=0;i<q;i++)
	{
		scanf("%d",&data[i].a);
		scanf("%d",&data[i].b );
		data[i].flg =-1;
	}
	for(int z=0;z<1000;z++)
	{
		if(x==data[z].a &&y==data[z].b )
		{
			data[z].flg =1;
		} 
    }
    for(int p=0;p<2;p++)
    {
	int j=0;
	while(s[j]!='\0')
	{

		if(s[j]=='U')
		{
			y+=1;
		}
		if(s[j]=='D')
		{
			y-=1;
		}
		if(s[j]=='L')
		{
			x-=1;
		}
		if(s[j]=='R')
		{
			x+=1;
		}
		
		for(int k=0;k<q;k++)
		{
			if(data[k].flg !=1)
			{
				if(x==data[k].a &&y==data[k].b )
				{
					data[k].flg =1;
				}
			}
		}
		j++;
	}
    }
	for(int t=0;t<q;t++)
	{
		if(data[t].flg ==1)printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}