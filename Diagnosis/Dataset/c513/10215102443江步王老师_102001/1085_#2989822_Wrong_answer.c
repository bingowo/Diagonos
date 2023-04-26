#include<stdio.h>
#include<string.h>
#define N 501
int sub(int *a, int la, int *b, int lb, int *res);

int main()
{
    char s1[N];
    char s2[N];
    int i;

    while (scanf("%s %s",s1,s2)==2)
    {
        int l1,l2;
        l1=strlen(s1);l2=strlen(s2);

        int a[N]={0};
        int b[N]={0};
        int res[N]={0};

        for (i=0;i<l1;++i)
        {
            a[i]=s1[l1-1-i]-'0';
        }
        for (i=0;i<l2;++i)
        {
            b[i]=s2[l2-1-i]-'0';
        }

        int flag=sub(a,l1,b,l2,res);
        if (!flag)
        {
            putchar('-');
            int len=0;
            for (i=N-1;i>=0;--i)
            {
                if (res[i]!=0)
                {
                    len=i;break;
                }
            }
            for (i=len;i>=0;--i)
            {
                printf("%d",res[i]);
            }
            putchar('\n');
        }
        else if (flag)
        {
            int len=0;
            for (i=N-1;i>=0;--i)
            {
                if (res[i]!=0)
                {
                    len=i;break;
                }
            }
            for (i=len;i>=0;--i)
            {
                printf("%d",res[i]);
            }
            putchar('\n');
        }
    }
    return 0;
}

int sub(int *a, int la, int *b, int lb, int *res)
{
    int flag=1;
    int i=0;
    if (lb>la)
    {
        flag=0;
    }
    else if (la==lb)
    {
        for (i=la-1;i>=0;--i)
        {
            if (b[i]>a[i])
            {
                flag=0;break;
            }
        }
    }

    i=0;
    if (flag)
    {
        while (i<=la-1)
        {
            int t=a[i]-b[i];
            if (t<0)
            {
                a[i]+=10;
                a[i+1]--;
            }
            res[i]+=a[i]-b[i];
            
            ++i;
        }
    }
    else if (!flag)
    {
        while (i<=lb-1)
        {
            int t=b[i]-a[i];
            if (t<0)
            {
                b[i]+=10;
                b[i+1]--;
            }
            res[i]+=b[i]-a[i];
            
            ++i;
        }
    }

    return flag;
}