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
		if(x&01==1) n++;
		x=x>>1;
	}
	return n;//n<=7 
}
int main()
{ int i,T,j,a,b,Y=0,zi,mu,g;
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
		for(j=0;(c=getchar())!='\n';j++){
			 Y=Y+yi(c);
		} 
		g=GCD(Y,j*8);
		zi=Y/g;
		mu=j*8/g;
		printf("%d/%d",zi,mu);
	}
 return 0;
}