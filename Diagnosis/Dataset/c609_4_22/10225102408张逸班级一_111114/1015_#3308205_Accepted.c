#include<stdio.h>
#include<stdlib.h>
#define max_n 10000
int main(){
    long long A,B;int flag1=0;
    scanf("%lld %lld",&A,&B);
    if(A<0){
        A=-A;
        flag1=1;
    }
    if(A==0){printf("0");return 0;}
    long long ans1,ans2;
    ans1=A/B;ans2=A%B;
    while(ans2%3==0&&B%3==0){
        ans2/=3;B/=3;//化为最简分式
    }
    int count=0;
    while(B){
        B/=3;//最简的分母是3的k次，小数点后就有k位数字
        count++;
    }
    long long s1[max_n];//整数部分
    long long s2[max_n];//小数部分
    long long s3[2*max_n];//答案
    int i=0,j=0,k=0,flag=0;
    while(ans1){//整数部分
        s1[i++]=ans1%3;
        ans1/=3;
    } 
    while(ans2){//小数部分的分子
        s2[j++]=ans2%3;
        ans2/=3;
    }
    for(int o=0;o<j;o++){//小数的录入，最小的放s3[0]处
        s3[k++]=s2[o];
    }
    while(k<count-1){//分数的值太小，分母决定了小数点后0的个数
        s3[k++]=0;
    }
    if(i==0)s3[k++]=0;//没有整数部分，要添0
    for(int o=0;o<i;o++){//整数部分的录入
        s3[k++]=s1[o];
    }
    int carry=0;
    for(int i=0;i<k;i++){
        s3[i]+=1+carry;
        if(s3[i]>2){
            s3[i]%=3;
            carry=1;
        }
        else carry=0;
    }
    if(carry==1){
        s3[k++]+=2;//进位数时的要加2
        i++;//更新小数点的位置
    }
    if(i==0){flag=1;}
    for(int i=0;i<k;i++){
        s3[i]-=1;
        if(s3[i]==-1){
            s3[i]=2;
        }
    }
    for(int o=k-1;o>=0;o--){
        if(flag1==1)
        {if(s3[o]==1)printf("2");
        else if(s3[o]==2)printf("1");
        else printf("0");
        }
        else printf("%lld",s3[o]);
        if(j!=0&&o==k-i){//在标记处点小数点
            printf(".");
        }
        if(flag==1&&o==k-1){//没有整数部分，输出第一个数之后就添小数点
            printf(".");
        }
    
    }
   return 0;
}