#include <stdio.h>
#include <stdlib.h>

long int putout(int a)
{
    if(a==1) return 1;
    if(a==2) return 2;
    if(a==3) return 4;
    if(a==4) return 8;
    else
        return putout(a-1)+2*putout(a-2)+4*putout(a-3)+8*putout(a-4);
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int c;
        printf("case #%d:\n",i);
        scanf("%d",&c);
        printf("%ld\n",putout(c));
    }
    return 0;
}
