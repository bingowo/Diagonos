#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 int main()
 {    char s[51];
		scanf("%s",s);
		int i=0,l=0;
		while(i<strlen(s))
		{    int p;
			for(p=i;p<strlen(s)&&s[p]!=s[p+1];p++);
			if((p-i)>l) l=p-i;
			i=p;
		}
		printf("%d",l);
		return 0;
}