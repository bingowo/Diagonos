#include<stdio.h>
#define N 9001

void input(int *a);
void output(int *a, int n);
void my_pow(int *res, int *a, int b);
void mul(int *res, int *a);
int main()
{ 
    int t;
    int i;

    scanf("%d\n",&t);
    for (i=0;i<t;++i)
    {
        int a[10]={0};
        int b;
        int n;
        int res[N]={1,0};
        input(a);
        scanf("%d %d\n",&b,&n);
        my_pow(res,a,b);
        printf("case #%d:\n",i);
        output(res,n);
    }
    return 0;
}

void input(int *a)
{
    char s[10];
    scanf("%s",s);
    int len=strlen(s);

    int i,j;
    for (i=0,j=len-1-i;i<len;++i,--j)
    {
        a[j]=s[i]-'0';
    }
    return;
}


void my_pow(int *res, int *a, int b)
{
    int i;
    for (i=0;i<b;++i)//进行b次res*a
    {
        mul(res,a);
    }
    return;
}

void mul(int *res, int *a)
{
    int t[N];
    int i,j;
    int len1=1,len2=1;
    for (i=0;i<N;++i)
    {
        t[i]=res[i];
    }
    for (i=0;i<N;++i)
    {
        res[i]=0;
    }

    for (i=N;i>=0;--i)
    {
        if (t[i]!=0)
        {
            len1=i+1;
            break;
        }
    }
    for (i=9;i>=0;--i)
    {
        if (a[i]!=0)
        {
            len2=i+1;
            break;
        }
    }

    for (i=0;i<len1;++i)
    {
        for (j=0;j<len2;++j)
        {
            res[i+j]+=t[i]*a[j];
            res[i+j+1]+=res[i+j]/10;
            res[i+j]=res[i+j]%10;
        }
    }
    return;
}

void output(int *a, int n)
{
    int i;
    for (i=n-1;i>=0;--i)
    {
        printf("%d",a[i]);
    }
    putchar('\n');
    return;
}