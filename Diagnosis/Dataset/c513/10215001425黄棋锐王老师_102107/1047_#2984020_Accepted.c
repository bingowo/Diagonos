#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{  int k,T;
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{ char s[501];
	 gets(s);
	 printf("case #%d:\n",k);
	 int i=0,j=1;
	 for(i=0;i<strlen(s);i++)
	 {
	 	if(s[i]!=s[i+1]||j==255) {
	 		printf("%d%c",j,s[i]);
	 		if(j==255) i++;
	 		j=1;
		 }
	 	if(s[i]==s[i+1]) j++;
	 }
	 putchar('\n');
	}
	return 0;
}