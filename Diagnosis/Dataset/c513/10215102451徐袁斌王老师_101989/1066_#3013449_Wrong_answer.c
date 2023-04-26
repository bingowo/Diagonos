#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int f(int x,int y,int z,int t)
{
	if(y<abs(x-t)) return 0;
	else if(y==abs(x-t)) {return 1;}
	else if(x==t&&y==0) return 0;
	else
	{
		if(x<z&&x>1)
		{
			return f(x-1,y-1,z,t)+f(x+1,y-1,z,t);
		}
		else if(x==z)return f(x-1,y-1,z,t);
		else if(x==1)return f(x+1,y-1,z,t);
		else return 0;
	}
}
int main()
{
	int n,p,m,t,j;
	scanf("%d",&j);
	for(int i=0;i<j;i++)
	{
		scanf("%d%d%d%d",&n,&p,&m,&t);
		if(m<abs(p-t)) printf("0\n");
		else printf("%d\n",f(p,m,n,t));
	}
	return 0;
 } 