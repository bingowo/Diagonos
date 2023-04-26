#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int a[510],i=0,len,b[500],j=0,num,f[10];
   int c[10][200];
   char s[510];
   scanf("%s",s);
   len=strlen(s);
   int l=len%3;
   for(i=0;i<len;i++)
   {
       a[i]=s[i]-'0';
   }
   if((len%3)==0)
   {
       for(i=0,j=0;i<len;i+=3,j++)
       {
           b[j]=a[i]*100+a[i+1]*10+a[i+2];
       }
       num=j;
       for(j=0;j<num;j++)
       {
           for(i=9;i>=0;i--)
           {
               c[i][j]=b[j]%2;
               b[j]=b[j]>>1;
           }
       }
       num--;

   }
   else if((len%3)==1)
   {
       for(i=0,j=0;i<(len-1);i+=3,j++)
       {
           b[j]=a[i]*100+a[i+1]*10+a[i+2];
       }
       b[j]=a[i];
       //printf("yushu=1 最后一个数=%d\n",b[j]);
       num=j;
       for(j=0;j<=num;j++)
       {
           if(j<num)
           {
               for(i=9;i>=0;i--)
               {
                   c[i][j]=b[j]%2;
                   b[j]=b[j]>>1;
               }
           }
           else
           {
               for(i=3;i>=0;i--)
               {
                   c[i][j]=b[j]%2;
                   b[j]=b[j]>>1;
               }
           }
       }

   }
   else if((len%3)==2)
   {
       for(i=0,j=0;i<(len-2);i+=3,j++)
       {
           b[j]=a[i]*100+a[i+1]*10+a[i+2];
       }
       b[j]=a[i]*10+a[i+1];
       //printf("yushu=2 最后一个数=%d\n",b[j]);
       num=j;
       for(j=0;j<=num;j++)
       {
           if(j<num)
           {
               for(i=9;i>=0;i--)
               {
                   c[i][j]=b[j]%2;
                   b[j]=b[j]>>1;
               }
           }
           else
           {
               for(i=6;i>=0;i--)
               {
                   c[i][j]=b[j]%2;
                   b[j]=b[j]>>1;
               }
           }
       }


   }
   for(i=9;i>=0;i--)
   {
       f[i]=len%2;
       len=len>>1;
   }
   printf("0001");

   for(i=0;i<10;i++)
   {
       printf("%d",f[i]);
   }

   for(j=0;j<=num;j++)
   {
       if(j<num)
        {
           for(i=0;i<10;i++)
           {
               printf("%d",c[i][j]);
           }
        }
        else
        {
            if(l==1)
            {
                    for(i=0;i<4;i++)
               {
                   printf("%d",c[i][j]);
               }
            }
            else if(l==2)
            {
                    for(i=0;i<7;i++)
               {
                   printf("%d",c[i][j]);
               }
            }
            else
            {
                    for(i=0;i<10;i++)
               {
                   printf("%d",c[i][j]);
               }
            }
        }
   }

   return 0;
}
