#include<stdio.h>
#include<string.h>
int main()
{
    int a[2000],b[2000];
    char s1[2000],s2[2000];
    while(scanf("%s",s1)&&scanf("%s",s2))
    {
        for(int i=0;i<2000;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        int len1=strlen(s1),len2=strlen(s2);
        for(int i=0;i<len1;i++) a[1999-i]=s1[len1-1-i]-'0';
        for(int i=0;i<len2;i++) b[1999-i]=s2[len2-1-i]-'0';
        int test=0;
        int next=0,tmp=0;
        int res[2000];
        for(int i=0;i<2000;i++) res[i]=0;
        if(len1>=len2&&a[2000-len1]>b[2000-len1])
        {
        for(int i=0;i<len1||i<len2;i++)
        {
            if(a[1999-i]+next>=b[1999-i])
            {
                res[1999-i]=a[1999-i]+next-b[1999-i];
                next=0;
            }
            else
            {
                tmp=0;
                while(a[1999-i]+next<b[1999-i])
                {
                    next+=10;
                    tmp++;
                }
                res[1999-i]=a[1999-i]+next-b[1999-i];
                next=-tmp;
            }
        }
        for(int i=0;i<2000;i++)
        {
            if(res[i]!=0) test=1;
            if(test==1) printf("%d",res[i]);
        }
        printf("\n");
        }
        else
        {
            int w[2000];
            for(int i=0;i<2000;i++) w[i]=a[i];
            for(int i=0;i<2000;i++) a[i]=b[i];
            for(int i=0;i<2000;i++) b[i]=w[i];
            for(int i=0;i<len1||i<len2;i++)
            {
            if(a[1999-i]+next>=b[1999-i])
            {
                res[1999-i]=a[1999-i]+next-b[1999-i];
                next=0;
            }
            else
            {
                tmp=0;
                while(a[1999-i]+next<b[1999-i])
                {
                    next+=10;
                    tmp++;
                }
                res[1999-i]=a[1999-i]+next-b[1999-i];
                next=-tmp;
            }
        }
        printf("-");
        for(int i=0;i<2000;i++)
        {
            if(res[i]!=0) test=1;
            if(test==1) printf("%d",res[i]);
        }
        printf("\n");
        }
    }
}