#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int qu(unsigned int x){
	int i;
	i=x&01;
	return i;
}
int f(unsigned int x,unsigned int y){
	int n=0;
	while(x>0||y>0){
		n+=qu(x)^qu(y);
		x=x>>1;
		y=y>>1;
	}
	return n;
}
int main()
{ int i,T,j;
unsigned int a,b;
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
		scanf("%u %u",&a,&b);
		printf("%d\n",f(a,b));
		
		
	}
 return 0;
}