#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(const void *a,const void *b)
{
    int x=*(int *)a;int y=*(int*)b;
    return x-y;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int num,f=1;
        scanf("%d",&num);
        int a[105]={0},b[105]={0},c[128]={0},d[128]={0};
        for(int j=0;j<num;j++)
        {
            scanf("%d%d",&a[j],&b[j]);
            c[a[j]]++;d[b[j]]++;
        }
        qsort(a,num,sizeof(int),cmp);
        for(int j=0;j<num-1;j++)
        {
            if (a[j]==a[j+1])
            {
                f=-1;break;
            }
        }
        for(int j=0;j<num;j++)
        {
            if(c[b[j]]!=d[a[j]])
            {
                f=-1;break;
            }
        }
        if(f==-1)
            printf("Poor dxw!\n");
        else
            printf("Lucky dxw!\n");
    }
    return 0;
}
