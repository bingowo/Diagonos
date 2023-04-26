#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void jia(int*a,int k)
{

   int j=(a[0]+1)/10;
   a[0]=(a[0]+1)%10;
   int d;
   for( d=1;d<k;d++)
   {
      int y=a[d];
      a[d]=(a[d]+j)%10;
      j=(y+j)/10;
   }
   if(j>0) {a[d]=j;k++;}



}

int pd(int*a,int k)
{
    for(int i=0;i<k-1;i++)
    if(a[i+1]==a[i]) return 0;
    return 1;
}



int main()
{

        int n;
        scanf("%d",&n);
    for(int h=0;h<n;h++)
    {
        int a[110]={0};
        char s[110];
        scanf("%s",s);
        int k=strlen(s);
        for(int e=0;e<k;e++)
        a[e]=s[e]-'0';

         for(int i=0;i<k/2;i++)
   {
       int c;
       c=a[i];
       a[i]=a[k-i-1];
       a[k-i-1]=c;//a调换位置
   }

         jia(a,k);

   while(pd(a,k)==0)
     jia(a,k);
        printf("case #%d:\n",h);
        for(int o=k-1;o>=0;o--)
         printf("%d",a[o]);
         printf("\n");




    }
    return 0;
}
