#include<stdio.h>
#include<string.h>
int main()
{
    int w,h,d;
    scanf("%d %d %d\n",&w,&h,&d);
    char c=getchar();
    d=d%360;
    //printf("%d %c",d,c);
    int s[201][201]={0};
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }
    /*for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            printf("%d",s[i][j]);
        }
    }*/
    if(c=='R')
    {
        if(d==0)
        {
            printf("%d %d\n",w,h);
            for(int i=0;i<h;i++)
            {
                 for(int j=0;j<w;j++)
                {
                    printf("%d ",s[i][j]);
                }
                printf("\n");
           }
        }
        if(d==90)
        {
            printf("%d %d\n",h,w);
            for(int j=0;j<w;j++)
            {
                for(int i=h-1;i>=0;i--)
                {
                    printf("%d ",s[i][j]);
                }
                printf("\n");
            }
        }
        if(d==180)
        {
            printf("%d %d\n",w,h);
            for(int i=h-1;i>=0;i--)
            {
                for(int j=w-1;j>=0;j--)
                {
                    printf("%d ",s[i][j]);
                }
                printf("\n");
            }
        }
        if(d==270)
        {
            printf("%d %d\n",h,w);
            for(int j=w-1;j>=0;j--)
            {
                for(int i=0;i<h;i++)
                {
                    printf("%d ",s[i][j]);
                }
                printf("\n");
            }
        }
    }
    else
    {
        if(d==0)
        {
            printf("%d %d\n",w,h);
            for(int i=0;i<h;i++)
            {
                 for(int j=0;j<w;j++)
                {
                    printf("%d ",s[i][j]);
                }
                printf("\n");
           }
        }
        if(d==270)
        {
            printf("%d %d\n",h,w);
            for(int j=0;j<w;j++)
            {
                for(int i=h-1;i>=0;i--)
                {
                    printf("%d ",s[i][j]);
                }
                printf("\n");
            }
        }
        if(d==180)
        {
            printf("%d %d\n",w,h);
            for(int i=h-1;i>=0;i--)
            {
                for(int j=w-1;j>=0;j--)
                {
                    printf("%d ",s[i][j]);
                }
                printf("\n");
            }
        }
        if(d==90)
        {
            printf("%d %d\n",h,w);
            for(int j=w-1;j>=0;j--)
            {
                for(int i=0;i<h;i++)
                {
                    printf("%d ",s[i][j]);
                }
                printf("\n");
            }
        }
    }
}
