#include <stdio.h>
#include <stdlib.h>


int cmp1(void*a,void*b)
{
    return *(int*)a>*(int*)b?1:-1;

}

int cmp2(void*a,void*b)
{
    return *(int*)a<*(int*)b?1:-1;

}

int main()
{
    char cdt;
    scanf("%c",&cdt);
    int a[100];
    int i=0;int k=0;
    while((scanf("%d",&a[i]))==1)
    {
        int j=0;
        for(j=0;j<i;j++)
        {
            if(a[i]==a[j]) {
                i--;
                break;
            }
        }
        i++;
    }
    if(cdt=='A') qsort(a,i-1,sizeof(a[0]),cmp1);
     else qsort(a,i-1,sizeof(a[0]),cmp2);
     for(k=0;k<i;k++)
     {
         printf("%d ",a[k]);
     }
    return 0;
}