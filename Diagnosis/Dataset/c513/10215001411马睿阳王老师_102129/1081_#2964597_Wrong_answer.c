#include<stdio.h>
int main()
{int T,i=0,j=1,k,a,n,t,c,d=0,l=0,h,e,p;
int s[1000]={0},temp[1000]={0};
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {scanf("%d %d",&a,&n);
  for(t=0;t<n-2;t++)
 { i=0,d=0,l=0;
   while(i<j)
  {s[0]=a;
   temp[i]=a*s[i]%10+d;
   d=a*s[i]/10;
   i++;
  }
  if(d>0) temp[i+1]=d;
  for(j=0;j<i;j++)
  {e=temp[j];temp[j]=s[j];s[j]=e;}
  for(l=0;l<j;l++)
  temp[l]=0;
 }
  for(h=0;h<i;h++)
  {p=s[h];s[h]=s[i-h-1];s[i-h-1]=p;}
   printf("case #%d:\n",k);
   for(j=0;j<i;j++)
   printf("%d\n",s[j]);
 }
 return 0;
}
