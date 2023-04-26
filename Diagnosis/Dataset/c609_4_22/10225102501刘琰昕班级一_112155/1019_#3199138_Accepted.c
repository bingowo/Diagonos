#include <stdio.h>
#include <stdlib.h>

int cmp(int *a,int *b)
{
    int an=0,bn=0,a1=*a,b1=*b;
    while(a1)an++,a1/=10;
    while(b1)bn++,b1/=10;
    if(an!=bn)return bn-an;
    else return *a-*b;
}
int main()
{
    int *a;
    a=(int *)malloc(1000000*sizeof(int));
    int i=0;
    while(scanf("%d",&a[i])!=EOF)i++;
    qsort(a,i,sizeof(int),cmp);
    for(int j=0;j<i;j++)
        printf("%d%s",a[j],j<i-1?" ":"\n");
}