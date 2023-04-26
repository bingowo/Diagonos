#include<stdio.h>

char change(int N,int R);
int main()
{
    int T,N,R,i;
    scanf("%d",&T);  //T表示测试数据的组数
    for(i = 0;i<T;i++){
        scanf("%d",&N);  //N表示要转换的数
        scanf("%d",&R);  //R表示所需要的进制
        change(N,R);
    }
    return 0;
}
char change(int N,int R)
{
    int a[10000000000],i = 0,flag;
    if (N<0){
        N = -N;
        flag = 1;
    }
    while(N){
        a[i]=N%R<10 ? N%R+'0':'A'+N%R-10;
        N = N/R;
        i++;
    }
    if(flag == 1) a[i]='-';
    for (int n = i;n>= 0;n--){
        printf("%c",a[n]);
    }
    return 0;
}