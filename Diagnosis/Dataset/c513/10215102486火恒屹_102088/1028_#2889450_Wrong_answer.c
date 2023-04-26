#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int cmpfunc1 (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}

int main()
{
    char a;
    scanf("%c",&a);
    char b;
    b=getchar();
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
    /*for(int i=0;i<100;i++)
        printf("%d ",num[i]);*/
    if(a=='A')
        qsort(num,n,sizeof(int),cmpfunc);
    else if(a=='D')
        qsort(num,n,sizeof(int),cmpfunc1);
    printf("%d ",num[0]);
    for(int i=1;i<n;i++)
    {
        if(num[i]!=num[i-1])
            printf("%d ",num[i]);
    }

    return 0;
}
