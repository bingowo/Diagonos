#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 500500
#define BigNUm 10007

void findKid(char *f,char *m){
    if(strcmp(f,"A")==0 && strcmp(m,"A")==0) printf("{A,O}");
    else if(strcmp(f,"A")==0 && strcmp(m,"B")==0) printf("{A,AB,B,O}");
    else if(strcmp(f,"A")==0 && strcmp(m,"AB")==0) printf("{A,AB,B}");
    else if(strcmp(f,"A")==0 && strcmp(m,"O")==0) printf("{A,O}");

    else if(strcmp(f,"B")==0 && strcmp(m,"A")==0) printf("{A,AB,B,O}");
    else if(strcmp(f,"B")==0 && strcmp(m,"B")==0) printf("{B,O}");
    else if(strcmp(f,"B")==0 && strcmp(m,"AB")==0) printf("{A,AB,B,O}");
    else if(strcmp(f,"B")==0 && strcmp(m,"O")==0) printf("{B,O}");

    else if(strcmp(f,"AB")==0 && strcmp(m,"A")==0) printf("{A,AB,B,O}");
    else if(strcmp(f,"AB")==0 && strcmp(m,"B")==0) printf("{A,AB,B,O}");
    else if(strcmp(f,"AB")==0 && strcmp(m,"AB")==0) printf("{A,AB,B,O}");
    else if(strcmp(f,"AB")==0 && strcmp(m,"O")==0) printf("{A,AB,B,O}");

    else if(strcmp(f,"O")==0 && strcmp(m,"A")==0) printf("{A,O}");
    else if(strcmp(f,"O")==0 && strcmp(m,"B")==0) printf("{B,O}");
    else if(strcmp(f,"O")==0 && strcmp(m,"AB")==0) printf("{A,AB,B,O}");
    else if(strcmp(f,"O")==0 && strcmp(m,"O")==0) printf("{O}");
}

int main(void)
{
	char f[3], m[3], k[3];
	scanf("%s%s%s", f, m, k);
    if(strcmp(k,"?")==0){
        printf("%s %s ",f,m);
        findKid(f,m);
    }

	return 0;
}
