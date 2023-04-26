#include<stdio.h>
#include<string.h>
int main()
{
    char s1[1000],s2[1000];
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        int a[1000],b[1000],w[1000];
        for(int i=0;i<1000;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        int len1=strlen(s1),len2=strlen(s2);
        for(int i=0;i<len1;i++) a[999-i]=s1[len1-1-i]-'0';
        for(int i=0;i<len2;i++) b[999-i]=s2[len2-1-i]-'0';
        int test=0;
        int next=0,tmp=0;
        int res[1000];
        for(int i=0;i<1000;i++) res[i]=0;
        if(len1>len2)
        {
        for(int i=0;i<len1||i<len2;i++)
        {
            for(int i=0;i<len1||i<len2;i++)
            {
            if(a[999-i]+next>=b[999-i])
            {
                res[999-i]=a[999-i]+next-b[999-i];
                next=0;
            }
            else
            {
                tmp=0;
                while(a[999-i]+next<b[999-i])
                {
                    next+=10;
                    tmp++;
                }
                res[999-i]=a[999-i]+next-b[999-i];
                next=-tmp;
            }
        }
        }
        for(int i=0;i<1000;i++)
        {
            if(res[i]!=0) test=1;
            if(test==1) printf("%d",res[i]);
        }
        printf("\n");
        }
        else if(len1<len2)
        {
            for(int i=0;i<1000;i++) w[i]=a[i];
            for(int i=0;i<1000;i++) a[i]=b[i];
            for(int i=0;i<1000;i++) b[i]=w[i];
            for(int i=0;i<len1||i<len2;i++)
            {
            if(a[999-i]+next>=b[999-i])
            {
                res[999-i]=a[999-i]+next-b[999-i];
                next=0;
            }
            else
            {
                tmp=0;
                while(a[999-i]+next<b[999-i])
                {
                    next+=10;
                    tmp++;
                }
                res[999-i]=a[999-i]+next-b[999-i];
                next=-tmp;
            }
        }
        printf("-");
        for(int i=0;i<1000;i++)
        {
            if(res[i]!=0) test=1;
            if(test==1) printf("%d",res[i]);
        }
        printf("\n");
        }
        else
        {
            int te=0;
            while(s1[te]-'0'==s2[te]-'0'&&s1[te]) te++;
            if(s1[te]>=s2[te])
            {
                for(int i=0;i<len1||i<len2;i++)
                {
                if(a[999-i]+next>=b[999-i])
                {
                res[999-i]=a[999-i]+next-b[999-i];
                }
                else
                {
                tmp=0;
                while(a[999-i]+next<b[999-i])
                {
                    next+=10;
                    tmp++;
                }
                res[999-i]=a[999-i]+next-b[999-i];
                next=-tmp;
                }
                }
                for(int i=0;i<999;i++)
                {
                if(res[i]!=0) test=1;
                if(test==1) printf("%d",res[i]);
                }
                printf("%d",res[999]);
                printf("\n");
                }
            else
                {
                for(int i=0;i<1000;i++) w[i]=a[i];
            for(int i=0;i<1000;i++) a[i]=b[i];
            for(int i=0;i<1000;i++) b[i]=w[i];
            for(int i=0;i<len1||i<len2;i++)
            {
            if(a[999-i]+next>=b[999-i])
            {
                res[999-i]=a[999-i]+next-b[999-i];
                next=0;
            }
            else
            {
                tmp=0;
                while(a[999-i]+next<b[999-i])
                {
                    next+=10;
                    tmp++;
                }
                res[999-i]=a[999-i]+next-b[999-i];
                next=-tmp;
            }
        }
        printf("-");
        for(int i=0;i<1000;i++)
        {
            if(res[i]!=0) test=1;
            if(test==1) printf("%d",res[i]);
        }
        printf("\n");
            }
        }
    }
}
