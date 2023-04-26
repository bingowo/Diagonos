#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{ int i,j,T;
  scanf("%d",&T);
  for(i=0;i<=T-1;i++)
  { char a[100];
    scanf("%s",a);
    long long int R=0;
    int length=strlen(a);
    for(j=0;j<length;j++)
    { if(a[j]=='1') R=R+pow(3,length-j-1);
      if(a[j]=='-') R=R-pow(3,length-j-1);
    }
    printf("case #%d:\n",i);
    printf("%lld\n",R);
  }
 return 0;
}

