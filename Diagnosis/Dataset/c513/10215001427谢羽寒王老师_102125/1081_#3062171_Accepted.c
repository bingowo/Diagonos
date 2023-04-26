#include <stdio.h>
#include <stdlib.h>
#define N 95
void mul(int *result,int a)       //乘一次
{
    int i,carry=0;
    for (i=0; i<N; i++)
    {
        int t=result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;
    }
}


int main()
{
    int i,a,n,T,j;


    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d",&a,&n);

        int result[95]={1};
        for (j=0; j<n; j++){
                mul(result,a);    }








       printf("case #%d:\n",i);
       int k=94,c;
        while((c=result[k])==0){k--;}
        for(;k>=0;k--){
            printf("%d",result[k]);

        }

    printf("\n");



    }




}