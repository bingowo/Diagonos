#include<stdio.h>
#include<stdlib.h>
const char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
	int a,r;
	scanf("%d%d",&a,&r);
	char *ans;
	ans=(char*)malloc(sizeof(char)*5000);
	int count=0;
	while(a){
		if(a%r>=0){
			ans[count++]=s[a%r];
			a/=r;
		}
		else{
			ans[count++]=s[a%r-r];
			a=a/r+1;
		}
	}
	int i=count-1;
	if(count!=0){
		for(;i>=0;i--)
		printf("%c",ans[i]);
	}else printf("0");
	free(ans);
	return 0;
}