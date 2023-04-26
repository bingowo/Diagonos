#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trans(int num,char *p){
	int ys;
	while(num){
		ys=num%2;
		*p=ys+'0';
		p++;
		num=num/2;
	}
	*p='\0';
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
	{
 		char s1[33],s2[33];
		int a,b;
		scanf("%d %d",&a,&b);
		trans(a,s1);
		trans(b,s2);
		//printf("%s\n%s",s1,s2);
		int count=0;
		if(strlen(s1)<=strlen(s2)){
			for(int j=0;j<strlen(s1);j++){
				if(s1[j]!=s2[j]){
					count++;
				}	
			}
			for(int j=strlen(s1);j<strlen(s2);j++){
				if(s2[j]=='1'){
					count++;
				}
			}
		}
		else{
			for(int j=0;j<strlen(s2);j++){
				if(s1[j]!=s2[j]){
					count++;
				}	
			}
			for(int j=strlen(s2);j<strlen(s1);j++){
				if(s1[j]=='1'){
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
    return 0;
}