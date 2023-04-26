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
    else if(strcmp(f,"B")==0 && strcmp(m,"AB")==0) printf("{A,AB,B}");
    else if(strcmp(f,"B")==0 && strcmp(m,"O")==0) printf("{B,O}");

    else if(strcmp(f,"AB")==0 && strcmp(m,"A")==0) printf("{A,AB,B}");
    else if(strcmp(f,"AB")==0 && strcmp(m,"B")==0) printf("{A,AB,B}");
    else if(strcmp(f,"AB")==0 && strcmp(m,"AB")==0) printf("{A,AB,B}");
    else if(strcmp(f,"AB")==0 && strcmp(m,"O")==0) printf("{A,AB,B}");

    else if(strcmp(f,"O")==0 && strcmp(m,"A")==0) printf("{A,O}");
    else if(strcmp(f,"O")==0 && strcmp(m,"B")==0) printf("{B,O}");
    else if(strcmp(f,"O")==0 && strcmp(m,"AB")==0) printf("{A,AB,B}");
    else if(strcmp(f,"O")==0 && strcmp(m,"O")==0) printf("{O}");
}

void findOther(char *p, char *k)
{
	if(strcmp(p, "A") == 0 && strcmp(k, "A") == 0) printf("{A,AB,B,O}");
	else if(strcmp(p, "A") == 0 && strcmp(k, "B") == 0) printf("{AB,B}");
	else if(strcmp(p, "B") == 0 && strcmp(k, "A") == 0) printf("{A,AB}");
	else if(strcmp(p, "B") == 0 && strcmp(k, "B") == 0) printf("{A,AB,B,O}");

	else if(strcmp(p, "A") == 0 && strcmp(k, "O") == 0)	printf("{A,B,O}");
	else if(strcmp(p, "O") == 0 && strcmp(k, "A") == 0) printf("{A,AB}");
	else if(strcmp(p, "B") == 0 && strcmp(k, "O") == 0) printf("{A,B,O}");
	else if(strcmp(p, "O") == 0 && strcmp(k, "B") == 0) printf("{AB,B}");

	else if(strcmp(p, "O") == 0 && strcmp(k, "O") == 0) printf("{A,B,O}");
	else if(strcmp(p, "AB") == 0 && strcmp(k, "AB") == 0) printf("{A,AB,B}");
	else if(strcmp(p, "AB") == 0 && strcmp(k, "A") == 0) printf("{A,AB,B,O}");
	else if(strcmp(p, "A") == 0 && strcmp(k, "AB") == 0) printf("{AB,B}");

	else if(strcmp(p, "AB") == 0 && strcmp(k, "B") == 0) printf("{A,AB,B,O}");
	else if(strcmp(p, "B") == 0 && strcmp(k, "AB") == 0) printf("{A,AB}");
	else if(strcmp(p, "AB") == 0 && strcmp(k, "O") == 0) printf("impossible");
	else if(strcmp(p, "O") == 0 && strcmp(k, "AB") == 0) printf("impossible");

}

int main(void)
{
	char f[3], m[3], k[3];
	scanf("%s%s%s", f, m, k);
    if(strcmp(k,"?")==0){
        printf("%s %s ",f,m);
        findKid(f,m);
    }
    else if(strcmp(f,"?")==0){
        findOther(m,k);
        printf(" %s %s",m,k);
    }
    else if(strcmp(m,"?")==0){
        printf("%s ",f);
        findOther(f,k);
        printf(" %s",k);
    }

	return 0;
}
