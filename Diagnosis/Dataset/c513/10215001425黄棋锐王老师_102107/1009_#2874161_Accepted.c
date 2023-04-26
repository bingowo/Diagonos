#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int GCD(int x,int y){
	int r;
	if(x%y==0) return y;
	else{
		r=x%y;
		GCD(y,r);
	}
	
}
int yi(char x){
	int n=0;
	while(x){
		  n++;
		x=x&(x-1);
	}
	return n;//n<=7 
}
void midu(char*a){
	int len=strlen(a);
	char t;
	int i,Y=0,zi=0,mu=0,g=0;
	for(i=0;i<len;i++){ t=a[i];
		Y=Y+yi(t);
	} 
	int size=8*len;
	g=GCD(Y,size);
	zi=Y/g;
	mu=size/g;
	printf("%d/%d\n",zi,mu);
	
}
int main()
{ int i,T,j;
    char c;
	scanf("%d\n",&T);
	for(i=0;i<T;i++){ char a[10000]={"\0"};
		for(j=0;(c=getchar())!='\n';j++){
			 a[j]=c;
		} 
		midu(a);
	}
 return 0;
}