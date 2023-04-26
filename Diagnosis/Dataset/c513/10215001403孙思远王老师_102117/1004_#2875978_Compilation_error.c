#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int in=0;
    double dou=0.0;
    while(scanf("%s",s)!=EOF)
    {
        int len,i,flag=0,pot,p=1;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]=='.')
            {
                flag=1;
                pot=i;
                break;
            }
        }
        if(flag)
        {
            for(i=0;i<pot;i++)
                dou=dou*10+s[i]-'0';
            for(i=pot+1;i<len;i++)
                {dou=dou*10+s[i]-'0';
                 p*=10;}
            dou/=p;
        }
        else
        {
            for(i=0;i<len;i++)
                in=in*10+s[i]-'0';
        }
        int n0=sizeof(int),n1=sizeof(double);
        int num;
        if(flag)
        {
            
        }
            else
            {
                int j=1<<(n0*8-1);
                for(i=0;i<n0*2;i++)
                {
                num=0;
                for(j=0;j<4;j++)
                {
                    if((in|j)==in)
                        num=num*2+1;
                    j=j>>1;
                }
                if(num>9)printf("%c",num+'a'-10);
                else printf("%d",num);
                num=0;
                for(j=0;j<4;j++)
                {
                    if((dou|j)==dou)
                        num=num*2+1;
                    j=j>>1;
                }
                if(num>9)printf("%c",num+'a'-10);
                else printf("%d",num);
                if(j>=0)printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

