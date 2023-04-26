#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int N=11000;
int main()
{ int T,s,i,j,p,k,l;
long long int a,n,b[11000]={0},t,carry;
while(scanf("%d\n",&a)!=EOF)
{
    if(a==0) break;
    else{
b[0]=1;t=0;
for(j=1;j<N;j++)
b[j]=0;
  for(j=0;j<a;j++)
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
 printf("%d",b[j]);
 
 printf("\n");
}}
    
}