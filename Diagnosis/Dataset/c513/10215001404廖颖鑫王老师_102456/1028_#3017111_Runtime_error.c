#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int cmp2(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    int n=0,i,a[100];
    char c;
 
    scanf("%c",&c);
    getchar();
    while(scanf("%d",a[n])!=EOF)
    {
        n++;
    }
    if(c=='A')
    qsort(a,n,sizeof(int),cmp1);
    if(c=='D')
      qsort(a,n,sizeof(int),cmp2);
    for (i = 0; i<n; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                a[i]=a[j];
                for(int k=j;k<n-1;k++)
                {
                    a[k]=a[k+1];
                }
                n--;
                i--;
            }
        }
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d",a[i]);
    return 0;
}
