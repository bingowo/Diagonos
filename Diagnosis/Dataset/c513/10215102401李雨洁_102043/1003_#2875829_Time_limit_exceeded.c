#include<stdio.h>
int A(int n)//得到十进制数的二进制补码中1的个数
{
    int count = 0,m=n;
    while(n)
    {
        n=n&(n-1);count++;
    }
    if(m<0) count = count+32;
    return count;
}
int main()
{
    int t;
    scanf("%d",&t);//t为输入的数据的组数
    for(int i=0;i<t;i++)
    {
        long n;
        scanf("%ld",&n);
        int a[n];
        int j;
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        int q;

        for(int m=0;m<n;m++)
        {
            for(int k=0;k<n;k++)
            {   if (A(a[m])>A(a[k]))
                {
                    q=a[k];a[k]=a[m];a[m]=q;
                }
                else if (A(a[m])==A(a[k]) && (a[m] < a[k]) )
                {
                    q=a[k];a[k]=a[m];a[m]=q;
                }
            }
        }
        printf("case #%d:\n",i);
        int p;
        for(p=0;p<n;p++) printf("%d ",a[p]);
        printf("\n");
    }
    return 0;
}
