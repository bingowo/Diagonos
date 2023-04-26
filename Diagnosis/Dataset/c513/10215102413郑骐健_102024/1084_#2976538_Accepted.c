#include <stdio.h>
int main()
{
    int n,m,T,p,sum;
    scanf("%d",&T);
    for (n=0;n<T;n++)
        {
        scanf("%d",&p);
        sum=1;
        for (m=0;m<p;m++){
            sum*=2;
        }
        printf("case #%d:\n",n);
        printf("%d\n",sum);
        }


    return 0;
  }