#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,k,d,number,i,l,x;
    scanf("%d",&l);
    for(x=0;x<l;x++)
    {
        d=1;
        number=0;
    scanf("%d %d",&m,&n);
    k=m^n;
    for(i=0;i<32;i++){if(k&d)number++;d=d<<1;}
    printf("%d\n",number);

    }
    return 0;
}
