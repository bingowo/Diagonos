#include <stdio.h>
#include <stdlib.h>


int main()
{
    int A;
    int k=0;
    scanf("%d",&A);
    int nc;
    for(int i=1;i<=10000;i++)
    {
        int su=A*i;
        nc=su;
        while((su%10==1)||(su%10==0))
        {
            su=su/10;
            if(su==0) break;
        }
        if(su==0) {k=1;break;}
    }
    if(k==0) printf("-1");
    else printf("%d",nc);
    return 0;
}
