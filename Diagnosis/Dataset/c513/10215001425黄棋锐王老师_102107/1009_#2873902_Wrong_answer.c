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
	return n;
}
int main()
{ int i,T,j,a,b;
    char c;
    char s[10000]={'\0'};
	scanf("%d\n",&T);
	for(i=0;i<T;i++){ int Y=0,zi=0,mu=0,g=0;
		for(j=0;(c=getchar())!='\n';j++){
		    Y=Y+yi(c);
		}
		
		j=j*8;
		g=GCD(Y,j);
		zi=Y/g;
		mu=j/g;
		printf("%d/%d\n",zi,mu);
	}
 return 0;
}