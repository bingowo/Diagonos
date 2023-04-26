#include<stdio.h>
#define L 501

void input(int *a);
void output(int *res, int n, int sign);
int sub(int *a, int *b, int *res, int n);

int main()
{
    int n;
    int sign;
    int a[2*L]={0};
    int b[2*L]={0};
    int res[2*L]={0};

    input(a);input(b);
    scanf("%d\n",&n);

    sign=sub(a,b,res,n);

    output(res, n, sign);

    return 0;
}

void input(int *a)
{
    char s[L];
    scanf("%s",s);

    int i=0;
    int j,k;
    while (s[i]!=0 && s[i]!='.') ++i;

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

void output(int *res, int n, int sign)
{
    if (sign<0) putchar('-');

    int p=L-1;
    int i;
    for (i=0;i<=L-1;++i)
    {
        if (res[i]!=0)
        {
            p=i;break;
        }
    }

    for (i=p;i<=L-1;++i)
    {
        printf("%d",res[i]);
    }
    putchar('.');

    for (i=L;i<L+n;++i)
    {
        printf("%d",res[i]);
    }

    return;
}

int sub(int *a, int *b, int *res, int n)
{
    int i;
    int flag;//flag=1代表符号为正
    int pa=L-1,pb=L-1;
    for (i=0;i<=L-1;++i)
    {
        if (a[i]!=0)
        {
            pa=i;break;
        }
    }
    for (i=0;i<=L-1;++i)
    {
        if (b[i]!=0)
        {
            pb=i;break;
        }
    }

    if (pa<pb) flag=1;
    else if (pa==pb)
    {
        while (a[pa]==b[pb] && pa<2*L-1) 
        {
            pa++;pb++;
        }

        if (a[pa]>=b[pb]) flag=1;
        else flag=-1;
    }
    else flag=-1;
    
    int t;

    if (flag>0)
    {
        for (i=2*L-1;i>L+n-1;--i)
        {
            t=a[i]-b[i];
            res[i]+=t;
            if (res[i]<0)
            {
                res[i]+=10;
                res[i-1]--;
            }
        }

        if (res[i+1]>=5) res[i]++;

        for (;i>=1;--i)
        {
            t=a[i]-b[i];
            res[i]+=t;
            if (res[i]<0)
            {
                res[i]+=10;
                res[i-1]--;
            }
        }
    }
    else if (flag<0)
    {
        for (i=2*L-1;i>L+n-1;--i)
        {
            t=b[i]-a[i];
            res[i]+=t;
            if (res[i]<0)
            {
                res[i]+=10;
                res[i-1]--;
            }
        }

        if (res[i+1]>=5) res[i]++;

        for (;i>=1;--i)
        {
            t=b[i]-a[i];
            res[i]+=t;
            if (res[i]<0)
            {
                res[i]+=10;
                res[i-1]--;
            }
        }
    }

    return flag;
}