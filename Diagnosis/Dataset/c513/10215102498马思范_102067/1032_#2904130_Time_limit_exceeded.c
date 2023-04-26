#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    int x,y;
    x=*(int*)a;
    y=*(int*)b;
    while(x!=-1&&y!=-1&&x==y)
    {
        x++;
        y++;
    }
    return y-x;
}
int main()
{
    int t;
    int n;
    int a[1000][51];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            for(int k=0;;k++)
            {
                scanf("%d",&a[j][k]);
                if(a[j][k]==-1)
                    break;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int r=0;r<n;r++)
        {
            int p=0;
            while(a[r][p+1]!=-1)
            {
                printf("%d ",a[r][p++]);
            }
            printf("%d\n",a[r][p]);
        }
    }
    return 0;
}