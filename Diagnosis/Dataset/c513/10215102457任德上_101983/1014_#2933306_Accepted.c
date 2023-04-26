#include<stdio.h>
int main(){
    int a,b,max,min,i,teg,mod,k,q;
    scanf("%d%d",&a,&b);
    teg=a/b;
    mod=a%b;
    int n1[50],n2[50];
    for(i=0;teg!=0;i++){
        n1[i]=teg%3;
        teg/=3;
    }
    for(k=0;b!=1&&mod!=0;k++){
        b=b/3;
        n2[k]=mod/b;
        mod=mod%b;
    }
    int carry=0;
    for(int m=k-1;m>=0;m--){
        n2[m]=n2[m]+1+carry;
        carry=0;
        while(n2[m]>=3){carry++,n2[m]-=3;}
    }
    for(int m=0;m<i;m++){
        n1[m]=n1[m]+1+carry;
        carry=0;
        while(n1[m]>=3){carry++,n1[m]-=3;}
    }
    q=i;
    if(carry!=0)n1[i++]=carry;
    for(int m=k-1;m>=0;m--){
        n2[m]=n2[m]-1;
        if(n2[m]==-1)n2[m]=2;
    }
    for(int m=0;m<q;m++){
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
    if(i==0)printf("0");
    if(k!=0)printf(".");
    for(int m=0;m<k;m++)printf("%d",n2[m]);
    return 0;
}
