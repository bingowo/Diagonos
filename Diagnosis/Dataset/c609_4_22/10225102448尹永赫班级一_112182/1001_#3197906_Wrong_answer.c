#include <stdio.h>
#include <stdlib.h>

int main()
{ int f,k=0;
   scanf("%d",&f);
   while (k<f)
   {int num,n,i,j,sum=0;
   int s[1000]={0};
   scanf("%d%d",&num,&n);
   for(i=0;num!=0;i++)
   {
       if(n<0)
       {
           n=-n;
       }
       sum=num%n;
       num=num/n;
       s[i]=sum;
   }
   for(j=i-1;j>=0;j--)
   {

       if(s[j]>=10)
        printf("%d",s[j]+55);
       else
        printf("%d",s[j]);
   }
   printf("\n");
   k=k+1;}
    return 0;
}
