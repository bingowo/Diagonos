#include <stdio.h>
#include <math.h>


int main()
{ int T,i,j,k,d,m=0; int a[100],b[100]; char c[50];
  scanf("%d",&T);
  for(i=0;i<=T-1;i++)
  { scanf("%d %d",&a[i],&b[i]);
  
  }
  for(j=0;j<=T-1;j++)
  {k=0;
   if(a[j]<0) {printf("-"); a[j]=-a[j];}
      while(a[j]!=0)
   {   d=a[j]%b[j];
       if(d<10)
       c[k]=d+48;
       else 
       c[k]=d+55;
       k++; a[j]=a[j]/b[j]; d=0;
       
    }
    for(m=k-1;m>=0;m--)
    { 
       printf("%c",c[m]);
        
    }
    printf("\n");
  }
    
    
    
return 0;
}