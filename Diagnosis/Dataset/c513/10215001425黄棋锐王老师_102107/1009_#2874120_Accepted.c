#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int GCD(int x,int y){
	int r;
	while(x%y){
		r=x%y;
		x=y;
		y=r;
	}
	return r;
}
//int yi(char x){
//	int n=0;
//	while(x>0){
//		if(x&01!=0) n++;
//		x=x>>1;
//	}
//	return n;//n<=7 
//}
 void midu(char*a){
	int len=strlen(a);
	char t;
	int i,Y=0,zi=0,mu=0,g=0;
	for(i=0;i<len;i++){ t=a[i];
		while(t){t=t&(t-1);
			Y++;
		}
	} 
	int wei=8*len;
	g=GCD(Y,wei);
	zi=Y/g;
	mu=wei/g;
	printf("%d/%d\n",zi,mu);
	
}
int main()
{ int i,T;
    char c;
	scanf("%d\n",&T);
	for(i=0;i<T;i++){ char a[20000]={"\0"};
		int j=0; 
		while((c=getchar())!='\n'){
			a[j++]=c;
		}
		midu(a);
	}
 return 0;
}
