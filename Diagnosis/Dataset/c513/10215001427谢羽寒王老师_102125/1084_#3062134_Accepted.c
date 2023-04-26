#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,N,T;
    long long result;

    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        result=1;
        while(N>0){
            result*=2;
            N--;
        }








       printf("case #%d:\n",i);
       printf("%lld\n",result);





    }




}