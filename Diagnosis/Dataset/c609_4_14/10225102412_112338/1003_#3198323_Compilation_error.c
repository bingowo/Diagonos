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
    for (int j=i;j>0;j--){
        printf("%d ",a[j-1]);
    }
}