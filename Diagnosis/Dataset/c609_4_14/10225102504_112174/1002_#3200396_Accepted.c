#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f(int a){
    int e,b=1,c=1,d=a%2;
    while(a){
        a>>=1;
        e=a%2;
        if(d!=e)
            b++;
        else {
            if(b>c)
            c=b;
            b=1;
     }
        d=e;
    }
    if(b>c)
        c=--b;
    return c;
    }

    int a,t;
    scanf("%d",&t);
    for(int g=0;g<t;g++){
    scanf("%d",&a);
    printf("case #%d:\n",g);
    printf("%d\n",f(a));}
    return 0;
}
