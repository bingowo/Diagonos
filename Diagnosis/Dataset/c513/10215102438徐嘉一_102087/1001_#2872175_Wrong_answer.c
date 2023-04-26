#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,R,A;long long int N;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
       while(scanf("%lld %d",&N,&R)!=EOF)
       {
           if(N==0) {printf("0\n");continue;}
           if(N<0){printf("-");N=-N;}
           int X=0,Z[100];
           while(N)
           {
               Z[X]=N%R;X++;N/=R;
           }
           for(int j=X;j>=0;j--)
           {
               if(Z[j]>=10)
               {
                   printf("%c",'A'+Z[X]-10);
               }
               else printf("%d",Z[X]);
           }
           printf("\n");

       }
    }

}
