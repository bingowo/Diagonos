#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000000007


int alp(char c)
{
	int flag=0;
	switch(c)
	{
		case 'R':flag=1;break;
		case 'B':flag=2;break;
		case 'Y':flag=3;break;
		case 'G':flag=4;break;
	}
	return flag;
}

int main() 
{ int k,T;
	scanf("%d",&T);
for(k=0;k<T;k++)
{	char s[200]={'\0'};
	int cnt[4]={0};
	char c[4]={'!','!','!','!'};
	scanf("%s",s);
	int l=strlen(s),i,t;
	int si[4]={0};
	for(i=0;i<l;i++)
	{	t=i%4;
		switch(t)
		{
			case 0:
			{ 
			if(s[i]=='!') cnt[0]++;
			else c[0]=s[i];
			si[0]=alp(c[0]);
			break;
			}
			
			case 1:
			{if(s[i]=='!') cnt[1]++;
			else c[1]=s[i];
				si[1]=alp(c[1]);
				break;
			}
			
			case 2:
			{if(s[i]=='!') cnt[2]++;
			else c[2]=s[i];
				si[2]=alp(c[2]);
				break;
			}
			
			case 3:
			{if(s[i]=='!') cnt[3]++;
			 else c[3]=s[i];
			si[3]=alp(c[3]);
				break;
			}
		}
	}
	int r=-1,b=-1,y=-1,g=-1;
	for(i=0;i<4;i++)
	{	if(c[i]=='R') r=i;
		if(c[i]=='B') b=i;
		if(c[i]=='Y') y=i;
		if(c[i]=='G') g=i;
	}
	if(r==-1) r=6-b-y-g;
	else if(b==-1) b=6-r-y-g;
	else if(y==-1) y=6-r-b-g;
	else if(g==-1) g=6-r-b-y;
	
	printf("case #%d:\n",k);
	printf("%d ",cnt[r]);
	printf("%d ",cnt[b]);
	printf("%d ",cnt[y]);
	printf("%d\n",cnt[g]);
}
	return 0;
}