#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[5]={0};
    int a,b,r,i=0,c[1001],p,q,j;
    scanf("%s",s);
    if(s[0]=='-')
    {
        if(s[1]>=48&&s[1]<=57&&s[2]=='i')
        {
            a=0;
            b=-(s[1]-48);
        }
        else if(s[1]=='i')
        {
            a=0;
            b=-1;
        }
        else if(s[1]>=48&&s[1]<=57&&s[2]==0)
        {
            a=-(s[1]-48);
            b=0;
        }
        else if(s[1]>=48&&s[1]<=57&&(s[2]=='+'||s[2]=='-'))
        {
            a=-(s[1]-48);
            if(s[3]=='i')
            {
                if(s[2]=='+')
                    b=1;
                else
                    b=-1;
            }
            else
            {
                if(s[2]=='+')
                    b=s[3]-48;
                else
                    b=48-s[3];
            }
        }
    }
    else
    {
        if(s[0]>=48&&s[0]<=57&&s[1]=='i')
        {
            a=0;
            b=s[0]-48;
        }
        else if(s[0]=='i')
        {
            a=0;
            b=1;
        }
        else if(s[0]>=48&&s[0]<=57&&s[1]==0)
        {
            a=s[0]-48;
            b=0;
        }
        else if(s[0]>=48&&s[0]<=57&&(s[1]=='+'||s[1]=='-'))
        {
            a=s[0]-48;
            if(s[2]=='i')
            {
                if(s[1]=='+')
                    b=1;
                else
                    b=-1;
            }
            else
            {
                if(s[1]=='+')
                    b=s[2]-48;
                else
                    b=48-s[2];
            }
        }
    }
    //printf("%d %d",a,b);
    do
    {
        if((a%2==0&&b%2==0)||(a%2!=0&&b%2!=0))
            r=0;
        else
            r=1;
        c[i++]=r;
        a=a-r;
        p=a;
        q=b;
        a=-(p-q)/2;
        b=-(p+q)/2;
    }while(a!=0||b!=0);
    for(j=i-1;j>=0;j--)
        printf("%d",c[j]);
    return 0;
}
