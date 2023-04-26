#include <stdio.h>
#include <stdlib.h>


int co;
void coof0(int n)
{

    if(n==0);
    else if((n%5==0)&&((n%10)!=0)) co++;
    else if(n%10==0) co++;
    if(n%5==0)
    {
        int mid=n/5;
        coof0(mid);
    }

}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j;
        co=0;
        scanf("%d",&n);
        for(j=1;j<=n;j++) coof0(j);

        printf("case #%d:\n",i);
        printf("%d\n",co);
    }
    return 0;
}
