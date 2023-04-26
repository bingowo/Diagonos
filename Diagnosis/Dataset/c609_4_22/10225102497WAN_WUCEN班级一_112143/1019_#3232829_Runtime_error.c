#include <stdio.h>
#include <stdlib.h>

int digitcmp(const void*a,const void *b)
{   int aa,bb,an=0,bn=0;
    aa=*(int*)a;
    bb=*(int*)b;
    if (*(int*)a<0) aa=-*(int*)a;
    if (*(int*)b<0) bb=-*(int*)b;
    do an++;
    while(aa/=10);
    do bn++;
    while(bb/=10);
    if(an>bn||an<bn)return an-bn;
    else return *(int*)b-*(int*)a;
    }

int main()
{
    int *x,i=0;
    while(scanf("%d",x+i)!=EOF)i++;
    qsort(x,i-1,4,digitcmp);
    i--;
    for(;i>=0;i--)
    printf("%d ",*(x+i));
    return 0;
}
