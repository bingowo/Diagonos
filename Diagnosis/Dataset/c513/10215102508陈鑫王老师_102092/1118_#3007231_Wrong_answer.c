#include<stdio.h>
#include<stdlib.h>
int main()
{
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&h,&w,&d,&c);
    int a[200][200];
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
            scanf("%d",&a[i][j]);
    }
    int temp=(d/90)%4;
    if(c=='R')
    {
       if(temp==0)
       {
           printf("%d %d\n",h,w);
           for(int i=0;i<w;i++)
           {
               for(int j=0;j<h;j++)
               {
                   printf("%d%c",a[i][j],j==h-1?'\n':' ');
               }
           }
       }
       else if(temp==1)
       {
           printf("%d %d\n",w,h);
           for(int j=0;j<h;j++)
           {
               for(int i=w-1;i>=0;i--)
               {
                   printf("%d%c",a[i][j],i==0?'\n':' ');
               }
           }
       }
       else if(temp==2)
       {
           printf("%d %d\n",h,w);
           for(int i=w-1;i>=0;i--)
           {
               for(int j=h-1;j>=0;j--)
               {
                   printf("%d%c",a[i][j],j==0?'\n':' ');
               }
           }
       }
       else
       {
           printf("%d %d\n",w,h);
           for(int j=h-1;j>=0;j--)
           {
               for(int i=0;i<w;i++)
               {
                   printf("%d%c",a[i][j],i==w-1?'\n':' ');
               }
           }
       }


    }
    else if(c=='L')
    {
        if(temp==0)
       {
           printf("%d %d\n",h,w);
           for(int i=0;i<w;i++)
           {
               for(int j=0;j<h;j++)
               {
                   printf("%d%c",a[i][j],j==h-1?'\n':' ');
               }
           }
       }
       else if(temp==1)
       {
           printf("%d %d\n",w,h);
           for(int j=h-1;j>=0;j--)
           {
               for(int i=0;i<w;i++)
               {
                   printf("%d%c",a[i][j],i==w-1?'\n':' ');
               }
           }
       }
       else if(temp==2)
       {
           printf("%d %d\n",h,w);
           for(int i=w-1;i>=0;i--)
           {
               for(int j=h-1;j>=0;j--)
               {
                   printf("%d%c",a[i][j],j==0?'\n':' ');
               }
           }
       }
       else
       {
           printf("%d %d\n",w,h);
           for(int j=0;j<h-1;j++)
           {
               for(int i=w-1;i>=0;i--)
                printf("%d%c",a[i][j],i==0?'\n':' ');
           }
       }
    }
    return 0;
}
