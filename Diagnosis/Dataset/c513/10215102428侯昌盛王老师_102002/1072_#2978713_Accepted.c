#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void R(char *road,int r,int i,long long int x,long long int y)
{
	//printf("%d\n",r);
	long long d=1LL<<r-1;
	if(x==0&&y==0){
		road[i]='\0';
		return;
	}
	if(r)
	{
		if(llabs(x)>llabs(y))
		{
			if(x>0){
				road[i]='E';
				x-=d;
			}
			else{
				road[i]='W';
				x+=d;
			}
		}
		else
		{
			if(y>0){
				road[i]='N';
				y-=d;
			}
			else{
				road[i]='S';
				y+=d;
			}
		}
		i++;
		r=r-1;
		return R(road,r,i,x,y);
		
	}
	else{
		road[i]='r';
		road[i+1]='\0';
		return;
	}
}

int main()
{
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	int r=1;
	long long d0,d1;
	while(x!=0||y!=0)
	{
		d0=1LL<<r;
		d1=1LL<<r-1;
		
		if(d0>=(llabs(x)+llabs(y)+1)&&(llabs(x)+llabs(y)+1>d1)) break;
		
		else r++;
		
	}
	//printf("%d\n",r);
	if(x==0&&y==0) r=0;
	char road[r];
	R(road,r,0,x,y);
	//printf("%s\n",road);
	int len=strlen(road),j;

	if(len!=r) printf("-1");
	else{
		printf("%d\n",r);
		for(j=len-1;j>=0;j--) printf("%c",road[j]);
	
	}
	return 0;
	
}