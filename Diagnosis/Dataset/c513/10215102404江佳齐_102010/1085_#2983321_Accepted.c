#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int s1[500]={0},s2[500]={0},s3[500];
    char a[500],b[500];
    while(~scanf("%s %s",a,b))
    {
        int m,n,len,i,flag=0;
        m=strlen(a);
        n=strlen(b);
        for(i=0;i<m;i++) s1[i]=a[m-i-1]-'0';
        for(i=0;i<n;i++) s2[i]=b[n-i-1]-'0';
        if(m>n)
        {
            len=m;flag=0;
            for(i=n;i<m;i++) s2[i]=0;
        }
        else if(m==n)
        {
            len=m;
            for(i=n-1;i>=0;i--)
            {
                if(s1[i]>s2[i])
                {
                    flag=0;break;
                }
                if(s1[i]<s2[i])
                {
                    flag=1;break;
                }
            }
        }
        else
        {
            len=n;flag=1;
            for(i=m;i<n;i++) s1[i]=0;
        }
        if(flag==0)
        {
            for(i=0;i<len;i++)
            {
                if(s1[i]>=s2[i]) s3[i]=s1[i]-s2[i];
                else
                {
                    s1[i]=s1[i]+10;
                    s1[i+1]=s1[i+1]-1;
                    s3[i]=s1[i]-s2[i];
                }
            }
        }
        if(flag==1)
        {
            for(i=0;i<len;i++)
            {
                if(s2[i]>=s1[i]) s3[i]=s2[i]-s1[i];
                else
                {
                    s2[i]=s2[i]+10;
                    s2[i+1]=s2[i+1]-1;
                    s3[i]=s2[i]-s1[i];
                }
            }
        }
        int k=0;
        for(i=0;i<len;i++)
        {
            if(s3[i]==0) k=0;
            else
            {
                k=1;break;
            }
        }
        if(k==0) printf("0\n");
        if(k!=0)
        {
            if(flag==0)
            {
                for(i=len-1;i>=0;i--)
                {
                    if(s3[i]!=0)
                    {
                        printf("%d",s3[i]);
                        i--;break;
                    }
                }
                for(;i>=0;i--)
                {
                    printf("%d",s3[i]);
                }
                printf("\n");
            }
            if(flag==1)
            {
                printf("-");
                for(i=len-1;i>=0;i--)
                {
                    if(s3[i]!=0)
                    {
                        printf("%d",s3[i]);
                        i--;break;
                    }
                }
                for(;i>=0;i--)
                {
                    printf("%d",s3[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

