#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
int f1(int target, int a[], int index)
{
    if(target==0) return 1;
    if (index>n||index==n) return 0;
    return (f1(target+a[index],a,index+1)||f1(target,a,index+1)||f1(target-a[index],a,index+1));
}
int main()
{ int sum=0,i,j,m,w[110],x,y;
  int s[111100]={0};
  scanf("%d",&n);
  for(i=0;i<n;i++)
   {scanf("%d",&w[i]); sum+=w[i];
   } 

   for(j=1;j<=sum;j++)
   {  if (f1(j,w,0)==1) printf("1");
       else if (f1(j,w,0)==0) printf("0");
   }
}