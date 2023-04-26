#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void R(char *road,int r,int i,long long int x,long long int y)
{
	//printf("%d\n",r);

	if(x==0&&y==0){
		road[i]='\0';
		return;
	}
	if(pow(2,r)>=(abs(x)+abs(y)+1)&&(abs(x)+abs(y)+1>=pow(2,r-1)))
	{
		if(abs(x)>abs(y))
		{
			if(x>0){
				road[i]='E';
				x-=pow(2,r-1);
			}
			else{
				road[i]='W';
				x+=pow(2,r-1);
			}
		}
		else
		{
			if(y>0){
				road[i]='N';
				y-=pow(2,r-1);
			}
			else{
				road[i]='S';
				y+=pow(2,r-1);
			}
		}
		i++;
		r=r-1;
		return R(road,r,i,x,y);
		
	}
	else return;
}

int main()
{
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	int r=1;
	while(x!=0&&y!=0)
	{
		if(pow(2,r)>=(abs(x)+abs(y)+1)&&(abs(x)+abs(y)+1>pow(2,r-1))) break;
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