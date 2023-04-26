#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int m,n,T,i,j,small,large;
    long long P=1,Q=1;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d%d",&m,&n);
        if(n>(m/2)) n=m-n;
        small=m-n;
        large=n;
        for (j = m; j > small; j--){P=P*j;}
        for (j = n; j > 0; j--){Q=Q*j;}
long long result;
result=P/Q;
        printf("case #%d:\n",i);
printf("%lld\n",result);






    }





  }