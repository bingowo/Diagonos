#include<stdio.h>
int main()
{
    int T,n[1000];int i;
    scanf("%d\n",&T);
    for(i=0;i<T;i++){
        scanf("%d",&n[i]);
    }
    for(int j=0;j<i;j++){
        trans(n[j]);
        printf("\n");
    }
    return 0;
}

trans(int n)
{
    int a[10000];int i=0;
    for (i;n>0;i++){
        a[i] = n%2333;
        n = n/2333;
    }
    for (int j=i;j>0;j--){
        printf("%d ",a[j-1]);
    }
}