#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int a[501],b[501],c[501],d[501];
    int x,y,z1 = 0, z2 = 0;
    scanf("%d",&x);
    for (int i=0;i<x;i++) scanf("%d",&a[i]);
    scanf("%d",&y);
    for (int j=0;j<y;j++) scanf("%d",&b[j]);
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
            if (a[i]==b[j]) {c[z1++] = b[j]; b[j] = -1;} 
        }
    }
    for (int j=0;j<y;j++) if (b[j]!=-1) d[z2++] = b[j];
    qsort(d,z2,sizeof(int),cmp);
    for (int i=0;i<z1;i++) printf("%d ",c[i]);
    for (int j=0;j<z2;j++) printf("%d ",d[j]);
    return 0;
}