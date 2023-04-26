#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r,k,i=0;
    scanf("%d %d",&n,&r);
    char table[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char a[33];
    do{
        k=n%r;
        if(k<0)
        {
            k=n-(n/r+1)*r;
            n=n/r+1;
        }
        else n=n/r;
        a[i++]=table[k];
    }while(n);
    for(i=i-1;i!=-1;i--)printf("%c",a[i]);
    return 0;
}
