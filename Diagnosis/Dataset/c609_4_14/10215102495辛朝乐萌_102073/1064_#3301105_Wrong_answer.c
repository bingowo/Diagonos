#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count(int a,int b)
{
    int li;
    if(a>b&&b==1){
        li=4*(a/b);
    }
    else if (a<b&&a==1){
        li=4*(b/a);
    }
    else{
        if(a>b){
            li=4*b*(a/b);
        }
        else{
            li=4*a*(b/a);
        }
    }
    return li;
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if (a==b) printf("%d",a*4);
    else{
        printf("%d", count(a,b));
    }
}