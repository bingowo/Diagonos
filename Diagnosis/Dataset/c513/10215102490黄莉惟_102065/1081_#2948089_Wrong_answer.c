#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 95
void mul(int *result,int a)
{
    int i,carry=0;
    for (i=0; i<N; i++)
    {
        int t=result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;
    }
}
int main(){
    int t,a,n,i;
    int result[100];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d",&a,&n);
        mul(result,a);
        printf("%s",result);
    }
}