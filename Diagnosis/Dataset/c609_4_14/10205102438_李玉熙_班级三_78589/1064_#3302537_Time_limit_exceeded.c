#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    m=m>=n?m:n;
    n=m>=n?n:m;
    int grith=0,dif=1;
    while(dif>0){
        grith+=4*n;
        dif=m-n;
        m=dif>=n?dif:n;
        n=dif>=n?n:dif;
    }
    printf("%d",grith);
}