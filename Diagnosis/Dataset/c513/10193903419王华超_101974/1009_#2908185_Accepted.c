#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  trans(unsigned char c){
	int jcount=0;
	while(c!=0){
		jcount+=(c&1);
		c>>=1;
	}
	return jcount;
}
int main()
{
    int cas;
    char s[5];
    scanf("%d",&cas);
    gets(s);
    for(int i=0;i<cas;i++)
	{
		char s[125];
		int sum,count=0;
		gets(s);
		for(int j=0;j<strlen(s);j++){
			count+=trans(s[j]);
		}
		sum=strlen(s)*8;
		for(int j=count;j>=1;j--){
			if((count%j==0)&&(sum%j==0)){
				count=count/j;
				sum=sum/j;
			}
		}
		printf("%d/%d\n",count,sum);
	}
    return 0;
}