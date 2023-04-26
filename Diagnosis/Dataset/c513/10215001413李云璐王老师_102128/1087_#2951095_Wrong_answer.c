#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void chuli(int*a,int k)
{
   for(int i=0;i<k/2;i++)
   {
       int c;
       c=a[i];
       a[i]=a[k-i-1];
       a[k-i-1]=c;//a调换位置
   }
   for(int o=0;o<k;o++)
   printf("%d",a[o]);
   a[0]=(a[0]+1)%10;
   int j=(a[0]+1)/10;
   for(int d=1;d<k;d++)
   {
      int f=a[d];
      a[d]=(a[d]+j)%10;
      j=(f+j)/10; 
   }
   if(j>0) {a[k]=j;k++;}
   for(int o=0;o<k;o++)
   printf("%d",a[o]);
   printf("\n");
}
   
   

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a[110]={0};
        int k=0;
        while(scanf("%d",&a[k])!=EOF)
        k++;//k是A的位数
        chuli(a,k);
        printf("case #%d:\n",i);
        
        
        
        
    }
    return 0;
}