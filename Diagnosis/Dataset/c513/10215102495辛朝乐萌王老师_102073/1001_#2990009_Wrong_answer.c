#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void print(int num)
{
    if(num<10){
        printf("%d",num);
    }
    else{
        printf("%c",num-10+'A');
    }
}

void divi(N,R)
{
    if(N>0){
        divi(N/R, R);
        print(N%R);
    }
}

int main()
{
    int t;
    int N,R;
    scanf("%d",&t);
    for (int i=t; i=0; i--) {
        scanf("%d %d",&N,&R);
        if(N<0){
            printf("-");
            N = -N;
        }
        divi(N, R);
        printf("\n");
    }
    return 0;
}
