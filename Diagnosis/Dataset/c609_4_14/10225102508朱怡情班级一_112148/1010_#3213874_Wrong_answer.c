#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
char key[]="0123456789ABCDEFGHIJ";

void f(int n,int r)
{
    if(n!=0){
        if(n%r>=0){
                f(n/r,r);
                printf("%c",key[n%r]);
        }
        else{
                f(n/r+1,r);
                printf("%c",key[n-(n/r+1)*r]);
        }
    }
}

int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    f(n,r);
    return 0;
}
