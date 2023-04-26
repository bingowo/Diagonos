#include<stdio.h>

int main()
{int N,i=0,j=0,k=0,t=0,n=0,m=0,y=1,temp=0,d=0;
 int a[10000]={0},b[10000]={0};
 while(scanf("%d",&N)!=0)
    {//把N转化为a数组,且为倒序储存
     while(N/y>0)
      {y*=10;
       i++;}//i是N的位数
       y/=10;
     for(j=0;j<i;j++)
       {a[j]=N/y;
        y*=10;
       }
     for(m=0,j=0;j<i;j++,m++)
        b[m]=a[j];
     //计算乘法
     for(n=0;n<i;n++)
         {a[n]=a[0]*b[n];
          temp=a[n]/10;
          a[n]%=10;
          }
     if(a[n-1]>10)
        {i++;
         a[n-1]%=10;
         a[n]/=10;
        }

     for(k=0;k<N-2;k++)
        {for(t=0;t<=i;t++)
             {
             for(n=0;n<i;n++)
                 {a[n+t]+=a[t]*b[n]+temp;
                 temp=a[n+t]/10;
                 a[n+t]%=10;
                 }
              if(a[n+t-1]>10)
                {i++;
                 a[n+t-1]%=10;
                 a[n+t]/=10;
                }
             }
        }
    //输出最后一位
     printf("%d",a[i-1]);
     for(d=0;d<i;d++)
         {a[d]=0;
          b[d]=0;
         }

    }
}
