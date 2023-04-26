#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max 8000
typedef struct
{	int sign;//符号 
	int cnt;//记录有效位数 
	int v[max];//记录每一位上的数字，v[0]个位，v[1]十位 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数

void itob(int N,int R,char*s){
	int sign=1,i=0,j=0,a=0;
	 if(N<0) N=-N,sign=-1;
	 while(N>0)
	 {
	 	a=N%R;
	 	if(0<=a&&a<=9) s[i]='0'+a;
		  
	 	else if(10<=a&&a<=35) {
	 		s[i]='A'+a-10;
		 }
		 N=N/R;
	 		 i++;
	 }
	 if(sign==-1) s[i++]='-';
	 s[i]='\0';
	 //for(j=i-1;j>=0;j--) printf("%c",s[j]);
}

int main() 
{ 	int t,T;
	scanf("%d",&T);
	for(t=0;t<T;t++)
 {
	char s[2000]={'\0'};
	int r,n;
	scanf("%d %d",&n,&r);
	int ant=0;
	int i,k,l,j;
	itob(n,r,s);
	l=strlen(s);
	for(i=0;i<l;i++)
	{	int te=0;
		if('0'<=s[i]&&s[i]<='9') te=s[i]-'0';
		else if('A'<=s[i]&&s[i]<='Z') te=s[i]-'A'+10;
		ant+=te;
	}
	itob(ant,r,s);
	l=strlen(s);
 	printf("case #%d:\n",t);
 	for(j=l-1;j>=0;j--) printf("%c",s[j]);
 	
 } 
    return 0;
}