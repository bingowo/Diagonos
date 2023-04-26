#include<stdio.h>
int field(int x,int y){
	int ret,t;
	while(x!=y){
		if(x<y){
			t=x;x=y;y=t;
		}
		ret+=y*4;
		x-=y;
	}
	ret+=x*4;
	return ret;
}

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);	
	printf("%d",field(x,y));
	return 0;
}