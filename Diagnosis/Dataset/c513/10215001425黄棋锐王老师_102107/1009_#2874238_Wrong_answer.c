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
	while(x>0){
		  n++;
		x=x&(x-1);
	}
	return n; 
}

int main()
{ int i,T,j;
    char c;
	scanf("%d\n",&T);
	for(i=0;i<T;i++){ int j,Y=0,zi=0,mu=0,g=0;
		for(j=0;(c=getchar())!='\n';j++)
		 Y=Y+yi(c);
	int size=8*j;
	g=GCD(Y,size);
	zi=Y/g;
	mu=size/g;
	printf("%d/%d\n",zi,mu);
	
	}
 return 0;
}