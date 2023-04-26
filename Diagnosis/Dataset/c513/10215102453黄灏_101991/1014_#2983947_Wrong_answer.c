#include <stdlib.h>
#include <stdio.h>

int main(){
    long long int A,B,n;
    scanf("%lld%lld",&A,&B);
    long long c=A/B;
    long long d=A%B; n=d;
    int s[60];//存放最终数据
    int s1[30];//存放整数
    int s2[30];//存放小数
    int i=0;
    do{
        s1[i]=c%3;
        c /=3;
        i++;
    } while (c);
    int j=0;
    for(i=i-1;i>=0;i--,j++){
        s[j]=s1[i];
    }//j的位置为小数点所在位置；
    int q=j;
    if(d){//存在小数部分
        int p=0;
        do{
            s2[p]=d%3;//d是分子
            d=d/3;
            B=B/3;//B是分母；
            p++;
        } while (d || B!=1);
        for(p=p-1;p>=0;p--,q++){
            s[q]=s2[p];
        }
    }
    int t=q;//小数最后一位的后一位
    int carry=0;//进位
    for(q=q-1;q>=j;q--){//与全1序列相加
        if(s[q]+1+carry >= 3){
            s[q]=s[q]+1+carry-3;
            carry=1;
        } else {s[q]=s[q]+1+carry; carry=0;}
    }
    for(int q=0;q<t;q++){
        if(s[q]-1 == -1) s[q]=2;
        else s[q]=s[q]-1;
    }
    for(int q=q-1;q>=j-1;q--){
        if (s[q]==0) t-=1;
        else break;
    }
    if(carry==1) printf("1");
    for(int m=0;m<t;m++){
        printf("%d",s[m]);
        if(n){
            if(m==j-1) {printf(".");}
        }
    }

    return 0;
}


