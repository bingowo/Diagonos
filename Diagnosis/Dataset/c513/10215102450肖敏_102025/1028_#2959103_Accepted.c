#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    int *a1 = (int *)a,*b1=(int *)b;
    return *a1-*b1;//sx
}
int cmp2(const void *a,const void *b)
{
    int *a1 = (int *)a,*b1=(int *)b;
    return *b1-*a1;//jx
}
int main() {
    char sign;
    scanf("%c",&sign);
    int n[101];
    int i=0;
    while(scanf("%d",&n[i]) != EOF)
        i++;
    if(sign == 'A')
        qsort(n,i,sizeof (n[0]),cmp1);
    else
        qsort(n,i,sizeof (n[0]),cmp2);
    for(int j=0;j<i;j++)
    {
        if(n[j] == n[j+1])
        ;
        else
            printf("%d ",n[j]);
    }
    return 0;
}
