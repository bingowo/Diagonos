#include<stdio.h>

int main()
{int T;
 int i=0,j=0,k=0,t=0,n,a[1000]={0};
 scanf("%d",&T);
 for(t=0;t<T;t++)
 {scanf("%d",&n);
  //假设w=0,x必须存在
  for(i=5;i<=1000;i++)
    {   if(n%3==0||n%3==1)
        {a[i]=n/3+n/2;}
        else a[i]=(n/3-1)*2+n/2+1;
    }
  if(n==0) a[0]=1;
  else if(n==1) a[1]=1;
  else if(n==2) a[2]=2;
  else if(n==3) a[3]=3;
  else if(n==4) a[4]=5;
  else
  {
    //假设在之前a的基础上多了4w
    k=n/4;
    for(j=1;j<k;j++)
    a[n]+=a[n-4*j]+n/2+1;
  }
  printf("%d\n",a[n]);
 }
return 0;
}
