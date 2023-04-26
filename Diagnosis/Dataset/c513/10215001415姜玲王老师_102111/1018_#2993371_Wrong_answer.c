#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 void reverse(char*a)
 {
     char c;
     c=a[0];
     a[0]=a[1];
     a[1]=c;
 }
 void plus(char*a,char*b)
 {
     int i,k,j,temp;
     char c[500]={0};
     i=strlen(a);
     k=strlen(b);
     for(j=0;j<i||j<k;j++)
     {
         if(a[j]==0) a[j]+='0';
         if(b[j]==0) b[j]+='0';
         temp=c[j]+a[j]+b[j]-2*'0';
         c[j]=temp%10+'0';
         c[j+1]+=temp/10;

     }
     if(c[j]) c[j]+='0';
     strcpy(a,c);
 }
 void mutiply(char*a,char*b)
 {
     char c[500]={0};
     int i=strlen(a);
     int j=strlen(b),k,h,temp;
     for(k=0;k<i;k++)
    {
        for(h=0;h<j;h++)
     {
     if(c[k+h]>='0') c[k+h]-='0';
     temp=(a[k]-'0')*(b[h]-'0')+c[k+h];
     c[k+h]=temp%10+'0';
     c[k+h+1]+=temp/10;
      }
     }
     if(c[k+h-1]) c[k+h-1]+='0';
     strcpy(a,c);

 }
int main()
{
    char*a[]={"1","2","3","5","7","11","31","71","91","32","92","13","73","14","34","74","35","95","16","76","17","37","97","38","98","79"};
    char b[200];
    scanf("%s",b);
    char c[26][3]={0};
    char d[500]={0};
    int i,k,j;
    for(i=0,k=0;i<strlen(b);i++,k++)
    {
        for(j=0;b[i]!=','&&i<strlen(b);i++,j++)
        {
            c[k][j]=b[i];
        }
        if(j==2)reverse(c[k]);
    }
    for(i=0;i<k;i++)
    {
        plus(d,c[i]);
        mutiply(d,a[k-1-i]);
    }
    for(i=strlen(d)-1;i>=0;i--) printf("%c",d[i]);


}
