#include<stdio.h>

char change(int N,int R);
int main()
{
    int N[10],R[10];
    int T,i,num;
    char a[100];
    scanf("%d",&T);  //T表示测试数据的组数
    for(i = 0;i<T;i++){
        scanf("%d",N[i]);  //N表示要转换的数
        scanf("%d",R[i]);  //R表示所需要的进制
    }
    for(i = 0;i<T;i++){
        a[100],num = change(N[i],R[i]);
        for (int n = num-1;n>= 0;n--){
            printf("%c",a[n]);
        }
        printf("\n");
    }
    return 0;
}
char change(int N,int R)
{
    char a[100];
    int i = 0,flag = 0;
    if (N<0){
        N = -N;
        flag = 1;
    }
    while(N){
        a[i]=N%R<10 ? N%R+'0':'A'+N%R-10;
        N = N/R;
        i++;
    }
    if(flag == 1) a[i]='-';i++;
    return a[100],i;
}
