#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void readn(char*s,int*co){
	char*p=s;
	while(*p)
	{   int dim=0,c=0,sign=1;//初始化 
		if(*p=='-') sign=-1,p++;
		else if(*p=='+') p++;
		while(isdigit(*p)) c=c*10+*p-'0',p++;
		if(c==0) c=1;//处理x
		if(*p=='x') p++;
		else{ co[0]=sign*c;return ;//处理最后一位 
		}
		if(*p=='^') p++;
		while(isdigit(*p)) dim=dim*10+*p-'0',p++;
		if(dim==0) dim=1;
		co[dim]=sign*c;
	}
}
void muti(char*s1,char*s2,int*co){
	int co1[52]={0};
	int co2[52]={0};
	readn(s1,co1);
	readn(s2,co2);
	int i,j;
	for(i=0;i<50;i++)
		for(j=0;j<50;j++){
			co[i+j]=co1[i]*co2[j];
		}
}
 int main()
 {
 	 char s1[52]={"\0"};
 	 char s2[52]={"\0"};
 	 while(scanf("%s%s",s1,s2)==2){
 		int co[52]={0};
 		int out[52]={0};
 		muti(s1,s2,co);
 		int i=0,j=0;
 		for(i=0;i<52;i++)
		 	{
 			if(co[i]) out[j++]=co[i];
			}
		for(j=j-1;j>0;j--)
			printf("%d ",out[j]);
			printf("%d\n",out[j]);
	  }
		return 0;
}