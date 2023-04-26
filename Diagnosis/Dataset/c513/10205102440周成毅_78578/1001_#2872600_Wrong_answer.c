#include <stdio.h>
#include <stdlib.h>
#define D 37
void tran(int a,int b)
{
    if(a<b)
    {
        if(a<10) printf("%d",a);
        else printf("%c",a-10+'A');
    }
    else
    {
        tran(a/b,b);
        if(a%b<10)printf("%d",a%b);
        else printf("%c",a%b-10+'A');
    }
}
int main()
{
    int T,N[D],R[D],i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
        {scanf("%d %d",&N[i],&R[i]);}
    for(int k=1;k<T;k++)
    {
        if(N[k]>=0) tran(N[k],R[k]);
        else printf("-");tran(-N[k],R[k]);
    }
    printf("\n");
}