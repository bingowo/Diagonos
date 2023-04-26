#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    int m,n;
    m = *(int *)a;
    n = *(int *)b;
    if(m != n)
        return m-n;
    else
        return 1;

}
void compare(int a[],int b[])
{
    int k=0,l=0,j=0;
    char temp[101]={0};
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
    for(j=0;j<101;j++)
        a[j] = temp[j];
    qsort(a,sizeof(a)-1,sizeof(int),cmp);
}
int main()
{
    int n,i,p,q,j;
    scanf("%d",&n);
    int a[101]={0},b[101]={0};
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
