#include<stdio.h>

int C(int n,int m)
{int i=0,j=0,d=1;
 for(i=n;i>=n-m+1;i--)
 {d*=i;}
 for(j=m;j>=1;j--)
  d/=j;
 return d;
}

int main()
{int T,i=0,j=0,k=0,t=0,n,sum=0;
 scanf("%d",&T);
 {for(i=0;i<T;i++)
 {
    scanf("%d",&n);
    if(n%4==0)
    {sum=C(n-1,4)+C(n-1,3)*5+C(n-1,2)*10+C(n-1,1)*10+5;}
    else if(n%4==1)
    {sum=C(n-1,4)+C(n-1,3)*5+C(n-1,2)*10+C(n-1,1)*10+5;}
    else if(n%4==2)
    {sum=(C(n-1,4)+C(n-1,3)*5+C(n-1,2)*10+C(n-1,1)*10+5)*2;}
    else
    {sum=(C(n-1,4)+C(n-1,3)*5+C(n-1,2)*10+C(n-1,1)*10+5)*3;}
 }
 printf("%d\n",sum);
 }
 return 0;
}
