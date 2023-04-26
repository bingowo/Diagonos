#include <stdio.h>
#include <stdlib.h>

int Con(int m)
{
    if(m!=0)
        return 1+Con(m/10);
    else
        return 0;
}

int cmp(const void* a, const void* b)
{
    int p=*(int*)a, q=*(int*)b;
    if(p<0)
        p=-p;
    if(q<0)
        q=-q;
    if(Con(p) != Con(q))
        return Con(q) - Con(p);
    else
        return *(int*)a - *(int*)b;
}

int main()
{
    int* s;
    s=(int*)malloc(1e6*sizeof(int));
    int n=0;
    do
        scanf("%d",&s[n++]);
    while(n<1e6 && (getchar()!='\n')) ;
    qsort(s,n,sizeof(int),cmp);
    for(int i=0; i<n; i++)
        printf("%d ",s[i]);
    printf("\n");
    free(s);
    return 0;
}
