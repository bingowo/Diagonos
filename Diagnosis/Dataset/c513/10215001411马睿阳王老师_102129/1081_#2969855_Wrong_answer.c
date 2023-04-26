#include<stdio.h>
int main()
{int T,i=0,j=0,k,a,n,t,c,d=0,l=0,h,e,p,x=1;
int s[1000]={0},temp[1000]={0},b[1000]={0};
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {scanf("%d %d",&a,&n);
  if(n==0) s[0]=1;
  else{
     s[0]=1;
    for(t=0;t<n;t++)
 { i=0,d=0,l=0;
   while(i<=x)
  {temp[j]=a*s[i]%10+d;
   d=a*s[i]/10;
   i++;
  }
  if(d>0) {temp[j+1]=d;s[i]=temp[j-i+2];}
  for(i=0;i<=j;i++)
  s[i]=temp[i];
  for(l=0;l<j;l++)
  temp[l]=0;
  x=j;
 }
  for(h=0,i=x;i>=0;h++,i--)
  b[h]=s[i];
  }
   printf("case #%d:\n",k);
   for(h=0;h<=x;h++)
   printf("%d",b[h]);
   printf("\n");
 }
 return 0;
}
