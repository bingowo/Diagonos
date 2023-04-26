#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        int a[10086];
        int k=0;
        scanf("%d",&n);
        do{
            int r=n%2;
            a[k++]=r;
            n=n/2;
        }while(n);
        int len=1,max=1;
       for(int i=0;i<k-1;i++)
       {
           if(a[i]!=a[i+1])
           {   len++;
               if(max<len){max=len;}
           }
           else
           {
               i=i+1;
               len=1;
           };
       }
      printf("case #%d:\n",cas);
      printf("%d\n",max);
    }
    return 0;
}
