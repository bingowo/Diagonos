#include<stdio.h>

int main()
{
    int a[20]={0};
    a[0]=1;
    a[1]=2;
    a[2]=4;
    a[3]=7;
   // a[4]=12;
    for(int i=4;i<=20;i++)
    a[i]=a[i-1]+a[i-1]-a[i-2]+a[i-3];


  int n;
  while(scanf("%d",&n)!=EOF&&n!=-1)
  {
printf("%d\n",a[n]);
  }



}
