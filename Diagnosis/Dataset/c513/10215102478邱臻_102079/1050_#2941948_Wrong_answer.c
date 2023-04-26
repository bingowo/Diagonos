#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(char*s){
	int i=0,j,len=strlen(s);
	char c;
	for(i=0,j=len-1;i<=j;i++,j--){
		c=s[i];s[i]=s[j];s[j]=c; 
	}  //字符串倒置 
}
int main() {
	int t,i,result,m1,m2,result1,result2; 
	char s[81],s1[81],s2[81];
	char *p1,*p2;
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++){
		result=0;result1=0;result2=0;
		scanf("%s%s%s",s1,s2,s);
		if(strstr(s,s1)==NULL || strstr(s,s2)==NULL){
			result=0;
		}
		else if(strcmp(s,s1)==0 && strcmp(s,s2)==0 && strcmp(s1,s2)==0){
			result=0;
		}
		else{  //限定s1先出现 s2后出现
		    p1=strstr(s,s1);p2=strstr(s,s2);
		    p1=strstr(s,s1);m1=p1-&s[0]+strlen(s1);
		    reverse(s);reverse(s2);
		    p2=strstr(s,s2);m2=strlen(s)-strlen(s2)-(p2-&s[0]);
		    result1=m1-m2>0?m1-m2:m2-m1;
			reverse(s);reverse(s2);
			p2=strstr(s,s2);m2=p2-&s[0]+strlen(s2);
		    reverse(s);reverse(s1);
		    p1=strstr(s,s1);m1=strlen(s)-strlen(s1)-(p1-&s[0]);
		    result2=m1-m2>0?m1-m2:m2-m1;
		    result=result1>result2?result1:result2;
		}
		printf("case #%d:\n%d\n",i,result);
	}
	return 0;
}