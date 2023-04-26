#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    char s[150];
    scanf("%s",s);
    long long int A=0,B=0,C=1;
    char *p=s;
    while (*p!='.'&&*p){
        A=A*3;
        if (*p=='1'){
            A+=1;
        }
        if (*p=='2'){
            A-=1;
        }
        p++;
    }
    if (*p){
        p++;
    }
    while (*p){
        B=B*3;
        C=C*3;
        if (*p=='1'){
            B+=1;
        }
        if (*p=='2'){
            B-=1;
        }
        p++;
    }
    if (B==0) { printf("&lld",A);}
    else if (B>0){
        if (A<0){
            A++;
            B=C-B;
        }
        if (A==0) { printf("%lld %lld",B,C);}
    }
    else if (B<0){
        if (A>0){
            A--;
            B=C+B;
        }
        if (A==0){
            printf("%lld %lld",B,C);
        } else{ printf("%lld %lld %lld",A,B,C);}
    }

    return 0;
}