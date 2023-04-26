#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N=11000;
int main()
{ int T,s,i,j,p,k,l;
long long int a,n,b[11000]={0},t,carry;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{ scanf("%lld %lld %d\n",&a,&n,&l);
p=0;
b[0]=1;t=0;s=0;
  printf("case #%d:\n",i);
for(j=1;j<N;j++)
b[j]=0;
  for(j=0;j<n;j++)
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
 if(j<l-1)
 {for(k=0;k<l-j-1;k++) printf("0");
     for(k=j;k>=0;k--) printf("%d",b[k]);}
 else 
 for(k=l-1;k>=0;k--) printf("%d",b[k]);
 
 printf("\n");
}
    
}