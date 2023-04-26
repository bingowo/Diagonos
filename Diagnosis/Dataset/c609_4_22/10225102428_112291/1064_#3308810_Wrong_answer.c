#include<stdio.h>
int main() {
	long long int x,y,t;
	scanf("%d%d",&x,&y);
	long long int ans=0;
	if(x>y)t=x,x=y,y=t;
	if(x==y)ans=2*(x+y);
	else{
            while(x){//每次均以为最短边
		        long long int a=y/x;
		        ans+=4*x*a;
		        y%=x;
		        if(x>y){
		            long long int m=x;
	                x=y;
	                y=t;
		        }
            }
	}
	printf("%d",ans);
	return 0;
}
