#include <stdio.h>

int change(int *a,int *b,int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i]==a[j]||b[i]==b[j])
                return 0;
        }
        for (int j=0;j<n;j++)
        {
            if (a[i]==b[j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T,n,a[101],b[101];
    scanf("%d",&T);
    for (int cas=0;cas<T;cas++)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        int flag=change(a,b,n);
        if (flag)
            printf("Lucky dxw!\n");
        else
            printf("Poor dxw!\n");
    }
    return 0;
}
