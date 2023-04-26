#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void sort1(int*s,int m)
{
    int cmp1(const void*a1,const void*a2)
    {
        int a=*(int*)a1;
        int b=*(int*)a2;
        return b-a;
    }
    qsort(s,m,sizeof(int),cmp1);
}
void sort2(int*s,int m)
{
    int cmp2(const void*a1,const void*a2)
    {
        int a=*(int*)a1;
        int b=*(int*)a2;
        return a-b;
    }
    qsort(s,m,sizeof(int),cmp2);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        int a[m+1],b[m+1],data=0;
        for(int k=0;k<m;k++)
        scanf("%d",&a[k]);
        for(int k=0;k<m;k++)
        scanf("%d",&b[k]);
        sort1(a,m);
        sort2(b,m);
        for(int k=0;k<m;k++)
        data=data+a[k]*b[k];
        printf("case #%d:\n",i);
        printf("%d\n",data);
    }
    return 0;
}