#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void trans(long long int N,int R)
{
    long long int c=N/R;
    int d=N%R;
    if(d<0){
        c++;
        d=(-R)+d;
    }
    trans(c,R);
    printf("%c",table[d]);
}

int main()
{
    long long int N;
    int R=-2;
    scanf("%lld",&N);
    if (N==0) printf("%c",table[0]);
    trans(N,R);
    printf("\n");
    return 0;
}