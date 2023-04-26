#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long R(long long x,long long y){
	if((x-y)%2==0) return 0;
	else return 1;
}
int main(){
	char s[2000];
	scanf("%s",s);//a+bi=(qr+q1i)*(-1+i)+r得到qr=(r-a+b)/2,qi=(r-a-b)/2
	 char*q;
	 long long qr,i,qrr,qii,l,r;
	 if(s[0]=='i')qr=0,qi=1;
	 else if(strcmp(s,"-i")) qr=0,qi=-1;
	else{ 
	 char*p=strchr(s,'i');
	 if(p==NULL) pr=atoi(s),pi=0; // 只有a 
	 if(p!=NULL){
	 }
	 else if(p==NULL){//处理 
	 	
	 } 
		
	}return 0;
}
