#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 1000000007

int main() 
{ int k,T;
	scanf("%d",&T);
for(k=0;k<T;k++)
{	//每连续四个为一组，i%4相同的位置上的字母一定一样，可分类为0，1，2，3 
	char s[200]={'\0'};
	int cnt[4]={0};//记录坏掉的数目 
	char c[4]={'\0'};//记录每类的字母 
	scanf("%s",s);
	int l=strlen(s),i,t;
	for(i=0;i<l;i++)
	{	t=i%4;//每连续四个为一组，i%4相同的位置上的字母一定一样，可分类为0，1，2，3 
		switch(t)
		{
			case 0:
			{ 
			if(s[i]=='!') cnt[0]++;
			else c[0]=s[i];
			break;
			}
			
			case 1:
			{if(s[i]=='!') cnt[1]++;
			else c[1]=s[i];
				break;
			}
			
			case 2:
			{if(s[i]=='!') cnt[2]++;
			else c[2]=s[i];
				break;
			}
			
			case 3:
			{if(s[i]=='!') cnt[3]++;
			 else c[3]=s[i];
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
	}//一定会至少给定其中三个字母 
	
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