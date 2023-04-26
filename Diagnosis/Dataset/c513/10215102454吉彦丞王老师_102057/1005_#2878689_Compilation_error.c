#include<stdio.h>
#include<string.h>
long double zhishu(long double b,int a)
{
    for(int i=0;i<a;i++)
    {
        b=b/8;
    }
    return b;
}
int main()
{
    int number;
    scanf("%d",&number);
    char a[number][100];
    long double answer[number];
    for(int i=0;i<number;i++)
    {
        scanf("s",&a[i][100]);
        int l=strlen(a[i][100]);
        long double x=0;
        for(int j=2;j<l;j++)
        {
            x=x+zhishu(long double(a[i][j]),j-1);
        }
        answer[i]=x;
    }
    for(int t=0;t<number;t++)
    {
        printf("case #%d:\n",t);
        printf("%lf\n",answer[t]);
    }
    return 0;
}