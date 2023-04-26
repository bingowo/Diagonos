#include<stdio.h>
int A(int n)//得到十进制数的二进制补码中1的个数
{
    int count = 0;
    while(n!=0)
    {
        if(n%2 == 1) count++;
        n=n>>1;
    }
    return count;
}
int main()
{
    int t;
    scanf("%d",&t);//t为输入的数据的组数
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int x,a[32];
        int j;
        for(j=0;j<n;j++)
        {
            while(scanf("%d",&x)!=EOF) a[j]=x;
        }
        int q;
        for(int m=1;m<j;m++)
        {
            if (A(a[m])>A(a[m-1]))
            {
                q=a[m-1];a[m-1]=a[m];a[m]=q;
            }
            if (A(a[m])==A(a[m-1]))
            {
                if(a[m]<a[m-1]){q=a[m-1];a[m-1]=a[m];a[m]=q;}
            }
        }
        printf("case #%d\n:",i);
        for(i=0;i<j;i++) printf("%d",a[i]);
    }
    return 0;
}
