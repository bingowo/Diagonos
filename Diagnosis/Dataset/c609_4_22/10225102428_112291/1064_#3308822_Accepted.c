#include<stdio.h>
int main() {
	unsigned long long int x,y,t;
	scanf("%llu%llu",&x,&y);
	unsigned long long int ans=0;
	if(x>y)t=x,x=y,y=t;
	if(x==y)ans=4*x;
	else{
            while(x!=0&&y!=0){//每次均以为最短边
		        unsigned long long int a=y/x;
		        ans+=4*x*a;
		        y%=x;
		        long long int m=x;
                x=y;
                y=m;
            }
	}
	printf("%llu",ans);
	return 0;
}
