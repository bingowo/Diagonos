#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long y[10000];
int num[10000]={0};
int main()
{
    int x,z;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d",&z);//z表示这一组有几个数
        for(int j=0;j<z;j++){
            scanf("%lld",&y[j]);
            for(int m=0,t=1;m<64;m++){//等到一个1的位数
                if(y[j]&t) num[j]++;
                t=t<<1;
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
        printf("case #%d:\n",i)
        for(int j=0;j<z;j++){
            printf("%lld ",y[j]);
        }
    }
    return 0;
}
