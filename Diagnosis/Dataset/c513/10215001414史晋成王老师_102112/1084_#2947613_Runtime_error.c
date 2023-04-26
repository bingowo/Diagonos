#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int i,j,n,t,a[100000]={0},k=0,flag=0,m,l;
a[0]=1;
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%d",&n);
 printf("case #%d:\n",i);
 if(n==0) printf("%d\n",1);
 else if(n>=1)
 { for(j=0;j<n;j++)
   { k=0;
     while(a[k]!=EOF)
     { a[k]*=2; a[k]+=flag;
     flag=0;
       if(a[k]>9) 
       {a[k]-=10; flag=1;}
       k++;
     }
     a[k]+=flag;
     flag=0;
   }
   if(a[k]==0) l=k-1; else l=k;
   for (m=l;m>=0;m--)
   {printf("%d",a[m]);
   }
   printf("\n");
   for(m=l;m>=0;m--)
   a[m]=0;
   a[0]=1;
 }
}
    
}