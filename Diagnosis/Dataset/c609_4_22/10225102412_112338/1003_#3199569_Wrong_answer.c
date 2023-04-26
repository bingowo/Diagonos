#include<stdio.h>
int main()
{
    int T;unsigned long long n[10000];int i;
    scanf("%d\n",&T);
    for(i=0;i<T;i++){
        scanf("%lu",&n[i]);
    }
    for(int j=0;j<i;j++){
        trans(n[j]);
    }
    return 0;
}

trans(int n)
{
    int a[10000];int i=0;
    if (n==0){
        printf("%d",0);
    }
    else{
        for (i;n>0;i++){
            a[i] = n%2333;
            n = n/2333;
        }
        for (int j=i;j>0;j--){
            printf("%d ",a[j-1]);
        }
    }
    printf("\n");
}