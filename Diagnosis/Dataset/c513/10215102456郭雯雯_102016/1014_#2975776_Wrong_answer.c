#include<stdio.h>
#define L 40

int main(){
    int A,B,log3[20];
    scanf("%d %d",&A,&B);
    log3[0]=1;
    int a=A/B,n;double b=(A%B)/B;
    for(int i=1;i<20;i++)log3[i]=3*log3[i-1];
    for(int i=1;i<20;i++)
        if(log3[i]==B){n=i;break;}
    int num[L];
    memset(num,0,sizeof(num));
    for(int i=20;i<L&&b!=0;i++){//小数
        b*=3;
        num[i]=(int)b;
        b-=num[i];
    }
    int m;
    for(m=19;m>=0&&a>0;m--){//整数
        num[m]=a%3;a/=3;
    }
    for(int i=m;i<L;i++)num[i]++;
    for(int i=m;i<L;i++){
        if(num[i]==3){num[i]=0;num[i-1]--;}
    }
    for(int i=m;i<L;i++)num[i]--;
    for(int i=m;i<L;i++){
        if(num[i]==-1)num[i]=2;
    }
    if(num[m-1]!=0)m--;
    for(int i=m;i<20;i++)printf("%d",num[i]);
    printf(".");
    for(int i=20;i<n+20;i++)printf("%d",num[i]);
    
}