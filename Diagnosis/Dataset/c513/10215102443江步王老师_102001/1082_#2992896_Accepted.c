#include<stdio.h>
#define L 501

void input(int *a);//输入浮点数
void output(int *res, int n);//输出浮点数
void add(int *a, int *b, int n);//实现浮点数加法

int main()
{
    int n;
    int a[2*L]={0};
    int b[2*L]={0};

    input(a);
    input(b);
    scanf("%d",&n);

    add(a,b,n);

    output(a,n);

    return 0;
}

void input(int *a)
{
    char s[L];
    scanf("%s",s);

    int i=0;
    while (s[i] != '.' && s[i]!=0) ++i;

    int j,k;
    
    for (j=L-1,k=i-1;k>=0;--j,--k)
    {
        a[j]=s[k]-'0';
        //printf("%d",a[j]);
    }
    //putchar('.');
    for (j=L,k=i+1;s[k]!=0;++j,++k)
    {
        a[j]=s[k]-'0';
        //printf("%d",a[j]);
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

void add(int *a, int *b, int n)
{
    int i;
    for (i=2*L-1;i>L+n-1;--i)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }

    if (a[i+1]>=5) a[i]++;

    for (;i>=1;--i)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }

   /*int pos=L-1;
    for (i=0;i<=L-1;++i)
    {
        if (a[i]!=0)
        {
            pos=i;break;
        }
    }

    for (i=pos;i<=L-1;++i)
    {
        printf("%d",a[i]);
    }
    putchar('.');
    for (i=L;i<L+n;++i)
    {
        printf("%d",a[i]);
    }*/
    return;
}