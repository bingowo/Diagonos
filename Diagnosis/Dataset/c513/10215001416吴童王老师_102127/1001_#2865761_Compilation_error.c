#include<stdio.h>
int main()
{
    int T;
    int a[100];
    int b[100];
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d%d\n",&a[i],&b[i]);
    }
    for(int j=0;j<T;j++);
    {
        char d[100];
        int k;
        for(k=0;a[j]>b[j];k++)
        {
            a[j]=a[j]/b[j];
            d[k]=a[j]%b[j]+48;
            if(d[k]>=10)
            {
                d[k]=a[j]%b[j]+55;
            }
        }
        for(;k>=0;k--)
        {
            scanf("%c",d[k]);
        }
    }
    return 0;
}