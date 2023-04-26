#include<stdio.h>
#include<string.h>
#include<math.h>
void f(int n,int p,int g[])//p为进制，g为储存数组
{
     int out[33];
     int u = 0, k = 0;//u和k用来计数
         while(n>0)
     {
    out[u++] = n % p;
    n /= p;
     }//out数组倒序存入二进制的数
     for(int j = u - 1;j >= 0;j--)
     {
            g[k]=out[j];
        k++;
     }//f数组存入二进制的数
     g[k] = -1;

}
int main()
{
     int t,n;//t是实验组数，n是每组的数据
     scanf("%d",&t);
     int b[];
     for(int i=0;i<t;i++)
     {
         scanf("%d",&n);
         printf("case #%d:\n",i);
     f(n,2,b);
     int max=1,length =1;
         for (int p1=0,p2=1;b[p1]!=-1&&b[p2]!=-1;p1++,p2++)
     {
         if(b[p1]!=b[p2])
     length++;
        else{
     if(length>max)
         max=length;
     length=1;
                }
     }
     if (max<length)max=length;
     printf("%d\n",max);

     }
         return 0;
}