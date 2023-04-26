#include <stdio.h>
#include <stdlib.h>
int main()
{ int N[100],R[100],m,T,n=0;
  scanf("%d",&T);
  for(m=0;m<=T-1;m++) scanf("%d %d",&N[m],&R[m]);
  while(n<=T-1)
  {   int count=0,a[100];
	if(N[n]>=0)
    {
        do
      {
		a[count++]=N[n]%R[n];
		N[n]=N[n]/R[n];
	  }while(N[n]!=0);
	for(int i=count-1;i>=0;i--) printf("%d",a[i]);
    printf("\n");
    };
    if(N[n]<0)
    {
        do
      {
		a[count++]=-N[n]%R[n];
		N[n]=N[n]/R[n];
	  }while(N[n]!=0);
    printf("-");
	for(int i=count-1;i>=0;i--) printf("%d",a[i]);
    printf("\n");
    };
    n++;
  }
  return 0;
}