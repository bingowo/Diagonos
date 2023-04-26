#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int m,n;
    //int a[m],b[n];
    scanf("%d",&m);
    int a[m];
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    scanf("%d",&n);
    int b[n];
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    int flagb[n];
    for(int e=0;e<n;e++) flagb[e]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(a[i]==b[j])
        {
            flagb[j]=0;      //出现过
            printf("%d ",a[i]);
        }
    }
    int count=0;
    int bb[n];
    for(int p=0;p<n;p++)
    {
        if(flagb[p]==1)
            {
                bb[count]=b[p];
                count++;
            }
    }
    qsort(bb,count,sizeof(bb[0]),cmp);
    for(int i=0;i<count;i++)
        printf("%d ",bb[i]);
    return 0;
}
