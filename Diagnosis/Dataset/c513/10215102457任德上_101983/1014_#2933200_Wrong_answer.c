#include<stdio.h>
int GCD(int a,int b){
    if(a%b==0)return b;
    for(int i=2;i<=b;i++){
        if(a%i==0&&b%i==0)return i*GCD(a/i,b/i);
    }
    return 1;

}
int main(){
    int a,b,max,min,i,teg,mod,k;
    scanf("%d%d",&a,&b);
    max=a>b?a:b;
    min=a>b?b:a;
    i=GCD(max,min);
    a/=i;
    b/=i;
    teg=a/b;
    mod=a%b;
    int n1[50],n2[50];
    for(i=0;teg!=0;i++){
        n1[i]=teg%3;
        teg/=3;
    }
    for(k=0;mod!=0;k++){
        b=b/3;
        n2[k]=mod/b;
        mod=mod%b;
    }
    int carry=0;
    for(int m=k-1;m>=0;m--){
        n2[m]=n2[m]+1+carry;
        while(n2[m]>=3){carry++,n2[m]-=3;}
    }
    for(int m=0;m<i;m++){
        n1[m]=n1[m]+1+carry;
        while(n1[m]>=3){carry++,n1[m]-=3;}
    }
    if(carry!=0)n1[i++]=carry;
    for(int m=k-1;m>=0;m--){
        n2[m]=n2[m]-1;
        if(n2[m]==-1)n2[m]=2;
    }
    for(int m=0;m<i;m++){
        n1[m]=n1[m]-1;
        if(n1[m]==-1)n1[m]=2;
    }
    for(int m=0;m<i/2;m++){
        int c;
        c=n1[m];
        n1[m]=n1[i-m-1];
        n1[i-m-1]=c;
    }
    for(int m=0;m<i;m++)printf("%d",n1[m]);
    if(k!=0)printf(".");
    for(int m=0;m<k;m++)printf("%d",n2[m]);
    return 0;


}