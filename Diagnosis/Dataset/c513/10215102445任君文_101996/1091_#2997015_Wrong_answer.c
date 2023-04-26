#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char c;
    int i=0;
    int a=0,b=0,n=0;
    int k1=1,k2=1;
    int f=0;
    while((c=getchar())!='\n')
    {
        if(c==' ')
        {
            scanf("%d",&n);
            break;
        }
        else if(c=='-')
        {
            if(i==0)
            {
                k1=-1;
            }
            else
            {
                k2=-1;
                f=1;
            }
        }
        else if(c=='+')
        {
            f=1;
        }
        else if(('0'<=c)&&(c<='9'))
        {
            if(f==0)
            {
                a=a*10+(c-'0');
            }
            else if(f==1)
            {
                b=b*10+(c-'0');
            }
        }
        else if(c=='i')
        {
            if(b==0)
            {
                b=1;
            }
        }
        i++;
    }
    b=b*k2;
    a=a*k1;
    printf("%d %d %d",a,b,n);
    return 0;
}