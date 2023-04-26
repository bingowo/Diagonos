#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int cmpfunc1 (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    char a;
    scanf("%c",&a);
    int num[102]={0};
    int n=0;
    char c;
    while((c=getchar())!='\n')
    {
        if(isdigit(c))
        {
            ungetc(c,stdin);
            scanf("%d",&num[n++]);
        }
    }
    if(a=='A')
        qsort(num,n+1,sizeof(int),cmpfunc);
    else if(a=='D')
        qsort(num,n+1,sizeof(int),cmpfunc1);
    printf("%d ",num[0]);
    for(int i=1;i<n;i++)
    {
        if(num[i]!=num[i-1])
            printf("%d ",num[i]);
    }

    return 0;
}
