#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    return *(int *)b-*(int *)a;
}
int main()
{ int T,a[11],i,j,k,m,n,l,count;
 scanf("%d",&T);
 for(i=0;i<T;i++)
 { for(j=0;j<9;j++)
     scanf("%d",&a[j]);
   printf("case #%d:\n",i);
    count=0;
    if(a[0]==0) count++;
     if(a[0]==1) printf("x^8");
     else if(a[0]==-1) printf("-x^8");
     else if(a[0]>1) printf("%dx^8",a[0]);
     else if(a[0]<-1) printf("%dx^8",a[0]);
    
   for(j=1;j<7;j++)
   { if(a[j]==0) {count++;continue;} 
      else if(a[j]==1) printf("+x^%d",8-j);
      else if(a[j]==-1) printf("-x^%d",8-j);
      else if(a[j]>1) printf("+%dx^%d",a[j],8-j);
      else if(a[j]<-1) printf("%dx^%d",a[j],8-j);
   }
   if(a[7]==0) {count++;} 
      else if(a[7]==1) printf("+x");
      else if(a[7]==-1) printf("-x");
      else if(a[7]>1) printf("+%dx",a[7]);
      else if(a[7]<-1) printf("%dx",a[7]);
   if(count==8&&a[8]==0) printf("0");
   else if(a[8]>0) printf("+%d",a[8]);
   else if(a[8]<0) printf("%d",a[8]);
   printf("\n");
 }
    
}