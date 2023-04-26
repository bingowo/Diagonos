#include<stdio.h>
int main()
{
    int T,n;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        trans(n);
    }
    return 0;
}
trans(int n)
{
    int a[100];
    for (int i=0;n>0;i++){
        a[i] = n%2333;
        n = n/2333;
    }
    for (i;i>0;i--){
        printf("%d ",a[i-1]);
    }
}