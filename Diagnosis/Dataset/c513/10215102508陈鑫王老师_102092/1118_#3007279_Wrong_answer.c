#include<stdio.h>
#include<stdlib.h>
int main()
{
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&h,&w,&d,&c);
    int a[200][200];
    int ret[200][200];
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
            scanf("%d",&a[i][j]);
    }
    int w1,h1,temp=(d/90)%4;
    if(c=='R')
    {
       if(temp==0)
       {
           w1=w;
           h1=h;
           for(int i=0,m=0;i<w;i++,m++)
           {
               for(int j=0,n=0;j<h;j++,n++)
               {
                   ret[m][n]=a[i][j];
               }
           }
       }
       else if(temp==1)
       {
           w1=h;
           h1=w;
           for(int j=0,m=0;j<h;j++,m++)
           {
               for(int i=w-1,n=0;i>=0;i--,n++)
               {
                   ret[m][n]=a[i][j];
               }
           }
       }
       else if(temp==2)
       {
           w1=w;
           h1=h;
           for(int i=w-1,m=0;i>=0;i--,m++)
           {
               for(int j=h-1,n=0;j>=0;j--,n++)
               {
                   ret[m][n]=a[i][j];
               }
           }
       }
       else
       {
           w1=h;
           h1=w;
           for(int j=h-1,m=0;j>=0;j--,m++)
           {
               for(int i=0,n=0;i<w;i++,n++)
               {
                ret[m][n]=a[i][j];
               }
           }
       }


    }
    else
    {
        if(temp==0)
       {
           h1=h;
           w1=w;
           for(int i=0,m=0;i<w;i++,m++)
           {
               for(int j=0,n=0;j<h;j++,n++)
               {
                   ret[m][n]=a[i][j];
               }
           }
       }
       else if(temp==1)
       {
           w1=h;
           h1=w;
           for(int j=h-1,m=0;j>=0;j--,m++)
           {
               for(int i=0,n=0;i<w;i++,n++)
               {
                   ret[m][n]=a[i][j];
               }
           }
       }
       else if(temp==2)
       {
           h1=h;
           w1=w;
           for(int i=w-1,m=0;i>=0;i--,m++)
           {
               for(int j=h-1,n=0;j>=0;j--,n++)
               {
                ret[m][n]=a[i][j];
               }
           }
       }
       else
       {
           h1=w;
           w1=h;
           for(int j=0,m=0;j<h-1;j++,m++)
           {
               for(int i=w-1,n=0;i>=0;i--,n++)
                ret[m][n]=a[i][j];
           }
       }
    }
    printf("%d %d\n",h1,w1);
    for(int i=0;i<w1;i++)
    {
        for(int j=0;j<h1;j++)
        {
            printf("%d%c",ret[i][j],j==h1-1?'\n':' ');
        }
    }
    return 0;
}
