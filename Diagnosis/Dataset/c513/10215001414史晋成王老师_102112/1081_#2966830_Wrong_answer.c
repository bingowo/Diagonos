#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int T,a,n,t,s,i,j,b[1000000]={0},p,k;
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%d %d",&a,&n);
p=0;
b[0]=1;t=0;s=0;
  printf("case #%d:\n",i);
 if(n==0) printf("1\n");
 else
 { for(j=0;j<n;j++)
   { t=0;s=0;
         while(b[p]!=0)
     { t=b[p]*a;
       b[p]=t%10;
       b[p]+=s;
       s=t/10;
       p++;
     }
     if(s!=0) b[p]=s;
     k=p;p=0;
   }
     
 
 for(j=k-1;j>=0;j--) printf("%d",b[j]);
 printf("\n");}
 memset(b,0,sizeof(b));
}
    
}