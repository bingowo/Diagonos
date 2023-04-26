#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num[105];
}NODE;
int cmp(const void* a,const void*b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    if(s1.num[0]!=s2.num[0])
        return s2.num[0]-s1.num[0];
    else
    {
        int temp=0;
        while(s1.num[temp]!=-1&&s2.num[temp]!=-1)
        {
            if(s1.num[temp]!=s2.num[temp])
                return s2.num[temp]-s1.num[temp];
            temp++;
        }
        if(s1.num[temp]!=-1)
            return -1;
        if(s2.num[temp]!=-1)
            return 1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        NODE a[n];
        for(int i=0;i<n;i++)
        {
            int k=0;
            while(1)
            {
                scanf("%d",&a[i].num[k]);
                if(a[i].num[k]==-1)
                    break;
                k++;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
        {
            int k=0;
            while(a[i].num[k]!=-1)
            {
                printf("%d ",a[i].num[k]);
                k++;
            }
            printf("\n");
        }
    }
    return 0;
}
