#include <stdio.h>

long long int x,y;
long long int ans;
int main()
{
	scanf("%d%d",&x,&y);
	while(x!=0&&y!=0){
		if(x>y){
			ans+=((x/y)*4*y);
			x%=y;
		}
		else{
			ans+=((y/x)*4*x);
			y%=x;
		}
	} 
	printf("%d",ans);
	return 0;
}