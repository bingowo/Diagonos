#include<stdio.h>
int count(int n)
{
    int a,A[20],i=0;
    while(n!=0){
        a=n%2333;
        n/=2333;
        A[i]=a;
        i++;
    }
    i--;
    for(;i>=0;i--){
        printf("%d ",A[i]);
    }
    return 0;
}
int main()
{
    int T;
    int N[300];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N[i]);
    }
    for(int j=0;j<T;j++){
        count(N[j]);
        printf("\n");
    }
    return 0;
}
