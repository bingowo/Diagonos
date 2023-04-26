#include<stdio.h>
char s[1000];
 
int main(){
    int n;
    scanf("%d",&n);
	while(~scanf("%s",s)){
		 int count=0;
		 int judge=1;
		 int i;
		 for(i=0;i<strlen(s);i++){
		 	if(s[i]=='(')count++;
		 	else if(s[i]==')')count--;
		 	if(count<0){
		 		printf("NO\n");
		 		judge=0;
				 break; 
		 	}
		 }
		 if(count==0&&judge==1)printf("YES\n");
		 else if(judge==1&&count!=0)printf("NO\n");
	}
	return 0;