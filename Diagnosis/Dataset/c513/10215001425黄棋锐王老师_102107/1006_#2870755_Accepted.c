#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{ char s[1000];
	char *p;
	int i,j,T,sum;
	scanf("%d\n",&T);
	for(i=0;i<T;i++){sum=0;
		scanf("%s",s);
		p=s;
		while(*p){
			if(*p=='1') sum=sum*3+1;
			else if(*p=='0') sum=sum*3+0;
			else if(*p=='-') sum=sum*3-1;
			p++;
		}
	    printf("case #%d:\n",i);
		printf("%d\n",sum);
	}
   
 return 0;
}