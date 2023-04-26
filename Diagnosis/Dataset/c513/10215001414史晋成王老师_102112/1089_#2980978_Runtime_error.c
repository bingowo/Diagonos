#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N=10000000;
int main()
{ int T,a,n,t,s,i,j,b[1000000]={0},p,k,carry,l;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{ scanf("%d %d %d\n",&a,&n,&l);
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
 
 for(j=N-1;j>=0;j--) 
 {if(b[j]!=0) {break;}}
 for(k=j;k>=0;k--) printf("%d",b[k]);
 printf("\n");}
 memset(b,0,sizeof(b));
}
    
}