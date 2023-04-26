#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main() {
	int T;
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		int fir=-1,val;
		printf("case #%d:\n",c);
		for(int i=8;i>=0;i--){
			scanf("%d",&val);
			if(val==0) continue;
			if(fir!=-1&&val>0) putchar('+');
			if(val==-1) putchar('-');
			else if(val!=1) printf("%d",val); 
			if(i>1) printf("x^%d",i);
			else if(i==1) putchar('x');
			fir=i;
			if((val==1||val==-1)&&i==0) putchar('1');
		}
		if(fir==-1) putchar('0');
		puts("");
	}
	return 0;
}