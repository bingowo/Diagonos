#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int slo(int a[],int n,int len)
{
    int t=0,carry=0;
    for(int i=0; i<len; i++)
    {
        t=a[i]*n+carry;
        a[i]=t%10;
        carry=t/10;
    }
    if(carry>0)
    {
        a[len]=carry;
        len++;
    }
    return len;
}
int main()
{
    char s[1005];
    int a[1005]= {0};
    a[0]=1;
    scanf("%s",s);
    int len=strlen(s);
    int id=1;
    if(len==1)
        printf("1");
    else
    {
        for(int i=0; i<len; i++)
        {
            if(i==0)
            {
                if(s[i]!=s[i+1])
                    id=slo(a,2,id);
            }
            else if(i==len-1)
            {
                if(s[i]!=s[i-1])
                    id=slo(a,2,id);
            }
            else
            {
                if(s[i-1]!=s[i]&&s[i-1]!=s[i+1]&&s[i+1]!=s[i])
                    id=slo(a,3,id);
                else if(s[i]==s[i-1]&&s[i]==s[i+1])
                    ;
                else
                    id=slo(a,2,id);
            }
        }
        int f=0;
        for(int i=1004; i>=0; i--)
        {
            if(a[i]==0&&f==0)
                continue;
            else
                f=1;
            printf("%d",a[i]);
        }
    }
    return 0;
}
