#include <stdio.h>
#include <stdlib.h>

int main()
{ int N[1000],R[1000],m,T,n=0;
  scanf("%d\n",T);
  for(m=0;m<=T-1;m++)
  scanf("%d %d\n",N[m],R[m]);
  whlie(n<=T-1)
  {   int c[50],d[50],i=0;
      c[0]=N[n];
      for(i=0;c[i]/R[n]!=0;i=i+1)
      { d[i]=c[i]%R[n];
        c[i+1]=(c[i]-d[i])/R[n];
      }
    for(p=i;p>=0;p=p-1)
    printf("%d",d[p]);
  }
  return 0;
}



