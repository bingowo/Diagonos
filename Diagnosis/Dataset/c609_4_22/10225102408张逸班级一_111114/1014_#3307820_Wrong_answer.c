#include<stdio.h>
#include<stdlib.h>
#define max_n 10000
int main(){
    long long A,B;
    scanf("%lld %lld",&A,&B);
    long long ans1,ans2;
    ans1=A/B;ans2=A%B;
    while(ans2%3==0&&B%3==0){
        ans2/=3;B/=3;
    }
    int count=0;
    while(B){
        B/=3;
        count++;
    }
    long long s1[max_n];//整数部分
    long long s2[max_n];//小数部分
    long long s3[2*max_n];
    int i=0,j=0,k=0,flag=0;
    while(ans1){
        s1[i++]=ans1%3;
        ans1/=3;
    } 
    while(ans2){
        s2[j++]=ans2%3;
        ans2/=3;
    }
    for(int o=0;o<j;o++){
        s3[k++]=s2[o];
    }
    while(k<count&&i==0){//没有整数部分，要添0
        s3[k++]=0;
    }
    for(int o=0;o<i;o++){
        s3[k++]=s1[o];//合并到s3中去
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
    }
    if(i==0){flag=1;}
    for(int i=0;i<k;i++){
        s3[i]-=1;
        if(s3[i]==-1){
            s3[i]=2;
        }
    }
    for(int o=k-1;o>=0;o--){
        printf("%lld",s3[o]);
        
        if(j!=0&&o==k-i){
            printf(".");
        }
        if(flag==1&&o==k-1){
            printf(".");
        }

    }
   return 0;
}