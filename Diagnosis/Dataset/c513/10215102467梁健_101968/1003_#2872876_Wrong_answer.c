#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int comp(const void *e1,const void *e2){
    long long* p1 = (long long* )e1;
    long long* p2 = (long long* )e2;
    int num1=0,num2=0;
    long long len1=*p1,len2=*p2;
    if(len1>=0){
        while(len1>0){
            if(len1%2==1)num1+=1;
            len1/=2;
        }
    }
    else{
        len1=-len1;
        while(len1>0){
            if(len1%2==1)num1+=1;
            len1/=2;
        }
        num1=64-num1;
    }
    if(len2>=0){
        while(len2>0){
            if(len2%2==1)num2+=1;
            len2/=2;
        }
    }
    else{
        len2=-len2;
        while(len2>0){
            if(len2%2==1)num2+=1;
            len2/=2;
        }
        num2=64-num2;
    }
    if(num1!=num2)return num2-num1;
    else return (long long* )e1-(long long* )e2;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        long long a[N];
        for(int n=0;n<N;n++){
            scanf("%lld",&a[n]);
        }
        qsort(a,N,sizeof(long long),comp);
        for(int m=0;m<N-1;m++){
            printf("%lld ",a[m]);
            }
        printf("%lld\n",a[N-1]);
    }
    return 0;
}
