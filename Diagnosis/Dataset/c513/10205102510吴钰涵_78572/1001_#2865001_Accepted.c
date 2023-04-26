#include <stdio.h>

void trans1(int num,int n)
{
    int c;
    int i;
    int a[32];
    for(i=0;num/n!=0;i++)
    {
        c=(num % n);
        a[i]=c;
        num = num/n;
    }
    a[i]=num;
    for (;i>=0;i--)
        printf("%d",a[i]);
    printf("\n");
}

void trans2(int num,int n)
{
    char arr[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char hex[16];
    int i=0,j=0;
    while (num>0)
    {
        hex[i++]=arr[num%n];
        num=num/n;
    }
        for (j=i-1;j>=0;--j)
            printf("%c",hex[j]);
        printf("\n");
}


int main()
{
    int T;
    scanf("%d\n",&T);
    for (int i=0;i<T;i++)
    {
        int num,n;
        scanf("%d %d",&num,&n);
        if (num<0)
        {
            num=-num;
            printf("-");
        }
        if (n>=2 && n<=9)
            trans1(num,n);
        else
            trans2(num,n);
    }
    return 0;
}