#include <stdio.h>
#include <math.h>


int main()
{ int T,i,j,k,d,m=0; int* a,b; char* c
  scanf("%d",&T)；
  for(i=0;i<=T-1;i++)
  { scanf("%d %d\n",&a[T],&b[T]);
  
  }
  for(j=0;j<=T-1;j++)
  {k=0;
      while(a[j])
   {   d=a[j]%b[j];
       if(d<10)
       c[k]='d';
       else 
       c[k]='d+55';
       k++; a[j]=a[j]-d; d=0;
       
    }
    for(m=0;m<k;m++)
    { if (m<k-1) printf("%c",c[m]);
      else printf("%c\n",c[m]);
        
    }
  }
    
    
    
return 0;
}