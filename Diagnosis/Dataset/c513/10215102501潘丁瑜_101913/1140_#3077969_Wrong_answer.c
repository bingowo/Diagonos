#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return *((int *)a) > *((int *)b) ? 1 : -1;
}
void compare(int a[],int b[])
{
    int k=0,l=0,j=0;
    char temp[1000]={0};
    while(a[k] != '\0')
    {
        while(b[l] != '\0')
        {
            if(a[k] == b[l])
                temp[j++] = a[k];
            l++;
        }
        k++;
        l=0;
    }
    int i;
    i=j;
    for(j=0;j<1000;j++)
        a[j] = temp[j];
    qsort(a,i,sizeof(int),cmp);
}
int main()
{
    int n,i,p,q,j;
    scanf("%d",&n);
    int a[1000]={0},b[1000]={0};
    for(i=1;i<n;i++)
    {
        scanf("%d",&p);
        for(j=0;j<p;j++)
            scanf("%d",&a[j]);
        a[j] = '\0';
        scanf("%d",&q);
        for(j=0;j<q;j++)
            scanf("%d",&b[j]);
        b[j] = '\0';
        compare(a,b);

        if(i+1<n)
        {
            scanf("%d",&p);
            for(j=0;j<p;j++)
                scanf("%d",&b[j]);
            b[j] = '\0';
            compare(a,b);
        }
    }
    i=0;
    while(a[i] != '\0')
    {
        printf("%d ",a[i]);
        i++;
    }
    return 0;
}