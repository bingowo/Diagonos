#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long y[10000];
int num[10000]={0};//扩大储存范围，数组初始化
int main()
{
    int x,z;
    long long t=1;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d",&z);//z表示这一组有几个数
        for(int j=0;j<z;j++){
            scanf("%lld",&y[j]);
            num[j]=0;
            t=1;
            for(int m=0;m<64;m++){//等到一个1的位数
                if(y[j]&t) num[j]++;
                t=t<<1;//计算补码中1的位数
            }
        }
        for(int j=0;j<z;j++){//实现排序的循环
            for(int t=j+1;t<z;t++){
                if(num[j]<num[t]){
                    int d=num[j];
                    num[j]=num[t];
                    num[t]=d;
                    long long h=y[j];
                    y[j]=y[t];
                    y[t]=h;
                }
                else if(num[j]==num[t]){
                    if(y[j]>y[t]){
                        long long h=y[j];
                        y[j]=y[t];
                        y[t]=h;
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        for(int j=0;j<z;j++){
            printf("%lld ",y[j]);
        }
        printf("\n");
    }
    return 0;
}
