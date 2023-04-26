#include<stdio.h>
int main()
{
    int T=0;
    long long n=0;
    int a[10]={0};
    int i=0,j=0,k=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        //初始化
        for(j=0;j<10;j++){
            a[j]=0;
        }
        j=0;
        scanf("%d",&n);
        //进制转化
        if(n==0){
            j++;
        }
        for(n=n;n>0;){
            a[j]=n%2333;
            n=n/2333;
            j++;
        }
        //输出
        for(k=j-1;k>=0;k--){
            printf("%d",a[k]);
            if(k!=0){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
    }
    return 0;
}
