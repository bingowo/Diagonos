
#include <stdio.h>

#include<stdlib.h>

    int method(int n)
    {
      if(n==1) return 1;
      else if(n==2) return 2;
      else if(n==3) return 4;
      else if(n==4) return 8;
      else return method(n-1)+method(n-2)+method(n-3)+method(n-4);
    }

    int main()
    {
        int T,n;
        scanf("%d",&T);
        for(int i=0;i<T;i++)
        {
            scanf("%d",&n);
            int m;
            m=method(n);
            printf("case #%d:\n",i);
            printf("%d",m);
        }
        return 0;
    }
