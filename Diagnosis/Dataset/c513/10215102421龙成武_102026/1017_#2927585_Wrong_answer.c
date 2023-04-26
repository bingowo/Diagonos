#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char c[51],*p,*q;
    long long int res,temp1,temp2;
    scanf("%s",c);
    q=c-1;
    p=c+strlen(c)-1;
    res=temp1=temp2=0;
    while(p!=q)
    {
        switch(*p)
        {
        case 'I':
            temp1=1;break;
        case 'V':
            temp1=5;break;
        case 'X':
            temp1=10;break;
        case 'L':
            temp1=50;break;
        case 'C':
            temp1=100;break;
        case 'D':
            temp1=500;break;
        case 'M':
            temp1=1000;break;
        }
        if(temp1!=temp2)
        {
            if(res<=temp1)
            {
                res+=temp1;
            }
            else
            {
                res-=temp1;
            }

        }
        else
        {
            res+=temp1;
        }
        temp2=temp1;
        p--;
    }
    printf("%lld",res);
    return 0;
}

