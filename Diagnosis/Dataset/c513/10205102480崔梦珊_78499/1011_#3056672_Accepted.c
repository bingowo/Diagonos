#include<stdio.h>
int main()
{
    char c=getchar();
    c=getchar();
    int res[16][2]=
    {
        {0,0},{1,0},{-1,1},{0,1},
        {0,-2},{1,-2},{-1,-1},{0,-1},
        {2,2},{3,2},{1,3},{2,3},
        {2,0},{3,0},{1,1},{2,1}
    };
    long long a=0;
    long long b=0;
    while((c=getchar())!='\n')
    {
        int q;
        if(c>=48&&c<=57)
        {
            q=c-48;
        }
        else
        {
            q=c-55;
        }
        /*printf("%d ",q);*/
        a=-4*a+res[q][0];
        b=-4*b+res[q][1];
        /*printf("%lld  %lld\n",a,b);*/
    }
    if(a>0)
    {
        if(b==1)
        {
            printf("%lld+i",a);
        }
        else if(b==-1)
        {
            printf("%lld-i",a);
        }
        else if(b==0)
        {
            printf("%lld",a);
        }
        else if(b>0)
        {
            printf("%lld+%lldi",a,b);
        }
        else if(b<0)
        {
            printf("%lld%lldi",a,b);
        }

    }
    else if(a<0)
    {
        if(b==1)
        {
            printf("%lld+i",a);
        }
        else if(b==-1)
        {
            printf("%lld-i",a);
        }
        else if(b==0)
        {
            printf("%lld",a);
        }
        else if(b>0)
        {
            printf("%lld+%lldi",a,b);
        }
        else if(b<0)
        {
            printf("%lld%lldi",a,b);
        }

    }
    else
    {
        if(b==1)
        {
            printf("i");
        }
        else if(b==-1)
        {
            printf("-i");
        }
        else if(b==0)
        {
            printf("0");
        }
        else
        {
            printf("%lldi",b);
        }
    }
}
