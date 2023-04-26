#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N=1000;
int main()
{ int T,a,n,t,s,i,j,b[1000000]={0},p,k,carry;
double x,y;
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%d %d",&a,&n);
p=0;
b[0]=1;t=0;s=0;
  printf("case #%d:\n",i);
 if(n==0) printf("1\n");
 else
 { for(j=0;j<n;j++)
   {  carry=0;
       for (k=0;k<N;k++)
    {
        t=b[k]*a+carry;
        b[k]=t%10;
        carry=t/10;
    }

   }
   y=a;x=0;
   for(j=0;j<n;j++)
   x+=log(y)/log(10);
 
 for(j=x-1;j>=0;j++) printf("%d",b[j]);
 printf("\n");}
 memset(b,0,sizeof(b));
}
    
}