#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    long long int n;
    int *s;
    s=malloc(sizeof(int)*100);
    for(int cas=0;cas<T;cas++)
    {

        int i=0;
        scanf("%lld",&n);
        do{
            s[i++]=n%2333;
            n=n/2333;

        }while(n!=0);
        for(;i--;i>=0)
            {printf("%d ",s[i]);}
        if(i=0) printf("%d",0);
        printf("\n");

    }
    return 0;
}