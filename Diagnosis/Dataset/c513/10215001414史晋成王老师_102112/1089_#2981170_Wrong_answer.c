#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int T,a,n,t,s,i,j,b[11000]={0},p,k,carry,l,N;
scanf("%d\n",&T);
for(i=0;i<T;i++)
{ scanf("%d %d %d\n",&a,&n,&l);
p=0;
b[0]=1;t=0;s=0;
  printf("case #%d:\n",i);
  for(j=0;j<n;j++)
   {  carry=0;
       for (k=0;k<N+10;k++)
    {
        t=b[k]*a+carry;
        b[k]=t%10;
        carry=t/10;
    }
    for(N=10000;N>=0;N--)
     if(b[N]!=0) break;
     N++;
   }
 
 for(j=N-1;j>=0;j--) 
 {if(b[j]!=0) {break;}}
 if(j<l-1)
 {for(k=0;k<l-j-1;k++) printf("0");
     for(k=j;k>=0;k--) printf("%d",b[k]);}
 else 
 for(k=l-1;k>=0;k--) printf("%d",b[k]);
 
 printf("\n");
 memset(b,0,sizeof(b));
}
    
}