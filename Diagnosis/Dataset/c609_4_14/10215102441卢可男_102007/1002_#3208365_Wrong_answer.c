#include <stdio.h>
#include <stdlib.h>

int  b_change(int n,int *a)
{
   int i=0;
   while(n)
   {
       a[i++]=n%2;
       n=n/2;
   }
   return i;//二进制长度
}
int main()
{
    int t,j;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        int n;
        scanf("%d",&n);
        int max=1;
        if(n==0)
        {
            max=1;
        }
        else
        {
          int a[100]={0};
          int len=b_change(n,a);
          int b1=a[0],b2,cnt=1;
          for(int i=1;i<len;i++)
          {
              b2=a[i];
              if(b1==b2)
              {
                  max=cnt<max?max:cnt;
                  cnt=1;//ziling
              }

              else
              {
                  cnt++;
              }
              b1=b2;
              max=cnt<max?max:cnt;

         }

        }
        printf("case #%d\n%d\n",j,max);
    }
    return 0;
}
