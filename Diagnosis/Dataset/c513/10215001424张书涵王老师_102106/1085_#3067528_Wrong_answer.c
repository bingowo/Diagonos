#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    char s[1003]={0};
    while(gets(s))
    {
        int k=0;
        int c[1000]={0};
        if(strcmp(s,"")==0)
            break;
        char s1[1000],s2[1000]={0},s3[1000]={0};
        int i,lenth1=0,lenth2=0;
        for(i=0;s[i];i++)
        {
            if(s[i]==' ')
            {
                for(i=i+1;s[i];i++)
                    s2[lenth2++]=s[i];
                break;
            }
            s1[lenth1++]=s[i];
        }
        if(lenth1>lenth2)
        {
            reverse(s1);reverse(s2);
            for(i=lenth2;i<lenth1;i++)
                s2[i]='0';
            for(i=0;s1[i];i++)
                c[i]=s1[i]-s2[i];
            for(i=0;i<lenth1;i++)
            {
                if(c[i]<0)
                {
                    c[i]=c[i]+10;
                    c[i+1]=c[i+1]-1;
                }
            }
            int lenth=lenth1;
            for(i=lenth1-1;i>=0;i--)
            {
                if(c[i]==0)
                    lenth--;
                else
                    break;
            }
            for(i=0;i<lenth;i++)
                s3[i]=c[i]+'0';
            reverse(s3);
        }
        else
        {
            if(lenth2>lenth1)
            {
                reverse(s1);reverse(s2);
                for(i=lenth1;i<lenth2;i++)
                    s1[i]='0';
                for(i=0;s2[i];i++)
                    c[i]=s2[i]-s1[i];
                for(i=0;i<lenth2;i++)
                {
                    if(c[i]<0)
                    {
                        c[i]=c[i]+10;
                        c[i+1]=c[i+1]-1;
                    }
                }
                int lenth=lenth2;
                for(i=lenth2-1;i>=0;i--)
                {
                    if(c[i]==0)
                       lenth--;
                    else
                        break;
                    }
                for(i=0;i<lenth;i++)
                    s3[i]=c[i]+'0';
                reverse(s3);
                k=-1;
            }
            else
            {
                for(i=0;s1[i];i++)
                {
                    if(s1[i]>s2[i])
                    {
                        reverse(s1);reverse(s2);
                        for(i=0;s1[i];i++)
                            c[i]=s1[i]-s2[i];
                        for(i=0;i<lenth1;i++)
                        {
                            if(c[i]<0)
                            {
                                c[i]=c[i]+10;
                                c[i+1]=c[i+1]-1;
                            }
                        }
                        int lenth=lenth1;
                        for(i=lenth1-1;i>=0;i--)
                        {
                            if(c[i]==0)
                                lenth--;
                            else
                                break;
                        }
                        for(i=0;i<lenth;i++)
                            s3[i]=c[i]+'0';
                        reverse(s3);
                        break;
                    }
                    if(s2[i]>s1[i])
                    {
                        reverse(s1);reverse(s2);
                        for(i=0;s2[i];i++)
                            c[i]=s2[i]-s1[i];
                        for(i=0;i<lenth2;i++)
                        {
                            if(c[i]<0)
                            {
                                c[i]=c[i]+10;
                                c[i+1]=c[i+1]-1;
                            }
                        }
                        int lenth=lenth2;
                        for(i=lenth2-1;i>=0;i--)
                        {
                            if(c[i]==0)
                                lenth--;
                            else
                                break;
                        }
                        for(i=0;i<lenth;i++)
                            s3[i]=c[i]+'0';
                        reverse(s3);
                        k=-1;
                        break;
                    }
                }
                if(s3[0]==0)
                    s3[0]='0';
            }
        }
        if(k==0)
            printf("%s\n",s3);
        else
            printf("-%s\n",s3);
    }
}