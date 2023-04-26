#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[21];//0结尾的个数
int b[21];//1结尾的个数
int counta(int n);
int countb(int n);
int main()
{
   int n,i;
   a[0]=0,b[0]=0;
   a[1]=1,b[1]=1;
   a[2]=2,b[2]=2;
   a[3]=4,b[3]=3;
   for(i=4;i<21;i++){a[i]=-1;b[i]=-1;}
   while((scanf("%d",&n))&&(n!=-1))
   {
       printf("%d\n",counta(n)+countb(n));
   }
   return 0;
}
int counta(int n)
{
    if(a[n]!=-1)return a[n];
    else
    {
        a[n]=counta(n-1)+countb(n-1);
        return a[n];
    }
}
int countb(int n)
{
    if(b[n]!=-1)return b[n];
    else
    {
        b[n]=countb(n-1)+counta(n-1)-countb(n-2);
        return b[n];
    }
}
