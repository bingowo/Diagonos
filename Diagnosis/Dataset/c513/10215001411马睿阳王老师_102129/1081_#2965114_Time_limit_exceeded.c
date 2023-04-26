#include<stdio.h>
int main()
{int T,i=0,j=1,k,a,n,t,c,d=0,l=0,h,e,p;
int s[1000]={0},temp[1000]={0};
 scanf("%d",&T);
 for(k=0;k<T;k++)
 {scanf("%d %d",&a,&n);
  if(n==0) s[0]=1;
  else{
     s[0]=1;
    for(t=0;t<n;t++)
 { i=0,d=0,l=0;
   while(s!=EOF)
  {
   temp[j-1]=a*s[i]%10+d;
   d=a*s[i]/10;
   i++;
   j++;
  }
  if(d>0) {temp[j]=d;s[i]=2;}
  for(i=0;i<=j;i++)
  s[i]=temp[i];
  for(l=0;l<j;l++)
  temp[l]=0;
 }
  for(h=0;h<i/2;h++)
  {p=s[h];s[h]=s[i-h-1];s[i-h-1]=p;}
  }
   printf("case #%d:\n",k);
   for(i=0;i<=j;i++)
   printf("%d",s[i]);
 }
 return 0;
}
