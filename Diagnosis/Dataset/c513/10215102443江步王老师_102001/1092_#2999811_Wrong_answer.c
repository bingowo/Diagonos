#include<stdio.h>
#include<string.h>
#define N 500

void mul(int *res, int a);
int main()
{
    char s[2*N+1];
    int res[N]={1,0};
    scanf("%s",s);
    char *p=s;
    
    while (*p)
    {
        int pos=0;
        if (p==s || *(p+1)==0)
        {
            if (*p != *(p+1))
                pos=2;
            else
                pos=1;
        }
        else
        {
            if (strcmp(p,p+1)==0 && strcmp(p,p-1)==0)
                pos=1;
            else if (strcmp(p,p+1)!=0 && strcmp(p,p-1)!=0)
                pos=3;
            else
                pos=2;
        }

        mul(res,pos);

        p++;
    }
    
    int len=0;
    for (int i=N-1;i>=0;--i)
    {
        if (res[i]!=0)
        {
            len=i;break;
        }
    }

    for (int i=len;i>=0;--i)
    {
        printf("%d",res[i]);
    }
    return 0;
}

void mul(int *res, int a)
{
    int t[N]={0};
    for (int i=0;i<N-1;++i)
    {
        t[i]+=(res[i]*a);
        t[i+1]+=(t[i]/10);
        t[i]=res[i]%10;
    }

    for (int i=0;i<N-1;++i)
    {
        res[i]=t[i];
    }
    return;
}