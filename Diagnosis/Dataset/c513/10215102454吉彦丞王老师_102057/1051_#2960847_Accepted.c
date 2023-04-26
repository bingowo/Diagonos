#include<stdio.h>
#include<string.h>
int zhishu(int n)
{
    int t=1;
    for(int i=0;i<n;i++)
    {
        t=t*2;
    }
    return t;
}
char base64(int t)
{
    if(t>=0&&t<=25)
    {
        return t+17+'0';
    }
    else if(t>=26&&t<=51)
    {
        return t+23+'0';
    }
    else if(t>=52&&t<=61)
    {
        return t-52+'0';
    }
    else if(t==62)
    {
        return '+';
    }
    else
    {
        return '/';
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        char s[100];
        scanf("%s",&s);
        int l=strlen(s);
        if(l%3==0)
        {
            int a[8*l];
            for(int j=0;j<l;j++)
            {
                for(int k=8*(j+1)-1;k>=8*j;k--)
                {
                    a[k]=s[j]%2;
                    s[j]=s[j]/2;
                }   
            }
            printf("case #%d:\n",i);
            for(int j=0;j<l*8/6;j++)
            {
                int t=0;
                for(int k=6*(j+1)-1;k>=6*j;k--)
                {
                    t=t+a[k]*zhishu(6*(j+1)-1-k);
                }
                printf("%c",base64(t));
            }
            printf("\n");
        }
        else
        {
            int m=8*l+6-(8*l%6);
            int a[m];
            for(int j=0;j<m;j++)
            {
                a[j]=0;
            }
            for(int j=0;j<l;j++)
            {
                for(int k=8*(j+1)-1;k>=8*j;k--)
                {
                    a[k]=s[j]%2;
                    s[j]=s[j]/2;
                }
            }
            printf("case #%d:\n",i);
            for(int j=0;j<m/6;j++)
            {
                int t=0;
                for(int k=6*(j+1)-1;k>=6*j;k--)
                {
                    t=t+a[k]*zhishu(6*(j+1)-1-k);
                }
                printf("%c",base64(t));
            }
            for(int j=0;j<4-(m/6)%4;j++)
            {
                printf("=");
            }
            printf("\n");
        }
    }
    return 0;
}