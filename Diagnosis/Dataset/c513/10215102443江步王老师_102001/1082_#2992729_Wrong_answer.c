#include<stdio.h>
#define L 500

void input(int *a);//输入浮点数
void output(int *res, int n);//输出浮点数
void add(int *a, int *b, int *res, int n);//实现浮点数加法

int main()
{
    int n;
    int a[2*L]={0};
    int b[2*L]={0};
    int res[2*L]={0};

    input(a);
    input(b);
    scanf("%d\n",&n);

    add(a,b,res,n);

    output(res,n);

    return 0;
}

void input(int *a)
{
    char s[L];
    scanf("%s",s);

    int i=0;
    while (s[i] != '.') ++i;

    int j,k;
    
    for (j=L-1,k=i-1;k>=0;--j,--k)
    {
        a[j]=s[k]-'0';
    }

    for (j=L,k=i+1;s[k]!=0;++j,++k)
    {
        a[j]=s[k]-'0';
    }

    return;
}

void output(int *res, int n)
{
    int i=0;

    while (res[i]==0 && i<=L-1) ++i;

    if (i==L)
    {
        printf("0.");
    }
    else
    {
        while (i<=L-1)
        {
            printf("%d",res[i]);
            ++i;
        }
        putchar('.');
    }

    int j=0;
    while (j<n)
    {
        printf("%d",res[i+j]);
        ++j;
    }

    return;
}

void add(int *a, int *b, int *res, int n)
{
    int i;
    for (i=2*L-1;i>L+n-1;--i)
    {
        res[i]+=a[i]+b[i];
        res[i+1]=res[i]/10;
        res[i]%=10;
    }

    if (res[i-1]>=5) res[i]++;

    for (;i>=0;--i)
    {
        res[i]+=a[i]+b[i];
        res[i+1]=res[i]/10;
        res[i]%=10;
    }
}