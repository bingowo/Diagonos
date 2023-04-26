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
int yi(int x){
	int n=0;
	while(x>0){
		if(x&01!=0) n++;
		x=x>>1;
	}
	return n;//n<=7 
}
int main()
{ int i,T,j,a,b;
    char c;
	scanf("%d\n",&T);
	for(i=0;i<T;i++){ int Y=0,zi=0,mu=0,g=0;
		for(j=0;(c=getchar())!='\n';){
			 Y=Y+yi(c);
			 if(0<=c&&c<=127) j=j+1;
			 else j=j+2;
		} 
		g=GCD(Y,j*8);
		zi=Y/g;
		mu=j*8/g;
		printf("%d/%d\n",zi,mu);
	}
 return 0;
}