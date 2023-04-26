#include <stdio.h>
#include <math.h>

int main()
{
    int n,r,a,x;
    scanf("%d%d",&n,&r);
    a=1;
    while(fabs(a*(-r-1))<fabs(n))
        a=a*r;
    if(a*n<0)
        a=a*r;
    while(a!=0){
        if(n*a<=0)
            printf("0");
        else{
            x=n/a;
            if(x*a!=n && x<-r-1)
                x=x+1;
            n=n-x*a;
            if(x<10)
                printf("%d",x);
            else
                printf("%c",x-10+'A');
        }
        a=a/r;
    }
    printf("\n");
    return 0;
}
