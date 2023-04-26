#include <stdio.h>
#include <stdlib.h>
int main()
{ int N[100],R[100],m,T,n=0;
  scanf("%d",&T);
  for(m=0;m<=T-1;m++) scanf("%d %d",&N[m],&R[m]);
  while(n<=T-1)
  {   int c[50],d[50],i=0,p;
      c[0]=N[n];
      for(i=0;c[i]/R[n]!=0;i++)
      {
        d[i]=c[i]%R[n];
        if()c[i+1]=(c[i]-d[i])/R[n];
      }
    for(p=i;p>=0;p=p-1) printf("%d",d[p]);
    printf("\n");
    n++;
  }
  return 0;
}


