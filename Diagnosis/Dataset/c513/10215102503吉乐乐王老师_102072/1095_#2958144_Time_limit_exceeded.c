#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000000
void cal1(int real[],int reta[],int retb[],int basereal,int baseima){
    int ta[N]={0},tb[N]={0};
    for(int i=N-1;i>0;i--){
        ta[i]=reta[i]*abs(basereal);tb[i]=retb[i]*abs(baseima);}
    for(int i=N-1;i>1;i--){
        ta[i-1]+=ta[i]/10;tb[i-1]+=tb[i]/10;
        ta[i]%=10;tb[i]%=10;
    }
    if((reta[0]==-1&&basereal>0)||(reta[0]==0&&basereal<0))ta[0]=-1;
    if((retb[0]==-1&&baseima>0)||(retb[0]==0&&baseima<0))tb[0]=-1;
    int i=1,j=1;//判断绝对值上谁大谁小
    int flag=1;//假定ta的绝对值比tb的绝对值大；
    while(ta[i]==0&&i<N)i++;
    while(tb[j]==0&&j<N)j++;
    if(i>j)flag=-1;//tb的绝对值比ta大；
    else if(i==j){
        for(;i<N;i++,j++){
            if(ta[i]>tb[j])break;
            else if(tb[j]>ta[i]){flag=-1;break;}
        }
    }
    if(ta[0]==-1&&tb[0]==-1){//负数计算判断
        if(flag==1){//ta的绝对值比tb大,所以是ta绝对值减tb绝对值，结果是负数
            for(i=N-1;i>1;i--){
                if(ta[i]<tb[i]){ta[i]+=10;ta[i-1]-=1;}
                ta[i]-=tb[i];
            }
            ta[0]=-1;
        }
        else{//tb的绝对值比ta大，所以是tb-ta，结果是正数
            for(int i=N-1;i>1;i--){
                if(tb[i]<ta[i]){tb[i]+=10;tb[i-1]-=1;}
                ta[i]=tb[i]-ta[i];
            }
            ta[0]=0;
        }
    }
    else if(ta[0]==-1&&tb[0]==0){//负数减正数,结果负数
        for(int i=N-1;i>1;i--){
            ta[i]+=tb[i];ta[i-1]+=ta[i]/10;ta[i]%=10;
        }
        ta[0]=-1;
    }
    else if(ta[0]==0&&tb[0]==-1){//正数减负数，结果正数
        for(int i=N-1;i>1;i--){
            ta[i]+=tb[i];ta[i-1]+=ta[i]/10;ta[i]%=10;
        }
        ta[0]=0;
    }
    else{//正数减正数
        if(flag==1){//a绝对值大于b
            for(i=N-1;i>1;i--){
                if(ta[i]<tb[i]){ta[i]+=10;ta[i-1]-=1;}
                ta[i]-=tb[i];
            }
            ta[0]=0;
        }
        else{
            for(int i=N-1;i>1;i--){
                if(tb[i]<ta[i]){tb[i]+=10;tb[i-1]-=1;}
                ta[i]=tb[i]-ta[i];
            }
            ta[0]=-1;
        }
    }
    for(int i=0;i<N;i++)real[i]=ta[i];
}
void cal2(int ima[],int reta[],int retb[],int basereal,int baseima){
    int ta[N]={0},tb[N]={0};
    for(int i=N-1;i>0;i--){
        ta[i]=reta[i]*abs(baseima);tb[i]=retb[i]*abs(basereal);}
    for(int i=N-1;i>1;i--){
        ta[i-1]+=ta[i]/10;tb[i-1]+=tb[i]/10;
        ta[i]%=10;tb[i]%=10;
    }
    if((reta[0]==-1&&baseima>0)||(reta[0]==0&&baseima<0))ta[0]=-1;
    if((retb[0]==-1&&basereal>0)||(retb[0]==0&&basereal<0))tb[0]=-1;
    int i=1,j=1;//判断绝对值上谁大谁小
    int flag=1;//假定ta的绝对值比tb的绝对值大；
    while(ta[i]==0&&i<N)i++;
    while(tb[j]==0&&j<N)j++;
    if(i>j)flag=-1;//tb的绝对值比ta大；
    else if(i==j){
        for(;i<N;i++,j++){
            if(ta[i]>tb[j])break;
            else if(tb[j]>ta[i]){flag=-1;break;}
        }
    }
    if(ta[0]==-1&&tb[0]==-1){//负数加负数
        for(int i=N-1;i>0;i--){
            ta[i]+=tb[i];ta[i-1]+=ta[i]/10;ta[i]%=10;
        }
        ta[0]=-1;
    }
    else if(ta[0]==-1&&tb[0]==0){//负数加正数,
        if(flag==1){
            for(int i=N-1;i>1;i--){
                if(ta[i]<tb[i]){ta[i]+=10;ta[i-1]-=1;}
                ta[i]-=tb[i];
            }
            ta[0]=-1;
        }
        else{
            for(int i=N-1;i>1;i--){
                if(tb[i]<ta[i]){tb[i]+=10;tb[i-1]-=1;}
                ta[i]=tb[i]-ta[i];
            }
            ta[0]=0;
        }
    }
    else if(ta[0]==0&&tb[0]==-1){//正数加负数
        if(flag==1){
            for(int i=N-1;i>1;i--){
                if(ta[i]<tb[i]){ta[i]+=10;ta[i-1]-=1;}
                ta[i]-=tb[i];
            }
            ta[0]=0;
        }
        else{
            for(int i=N-1;i>1;i--){
                if(tb[i]<ta[i]){tb[i]+=10;tb[i-1]-=1;}
                ta[i]=tb[i]-ta[i];
            }
            ta[0]=-1;
        }
    }
    else{//正数加正数
        for(i=N-1;i>1;i--){
            ta[i]+=tb[i];ta[i-1]+=ta[i]/10;ta[i]%=10;
        }
        ta[0]=0;
    }
    for(int i=0;i<N;i++)ima[i]=ta[i];
}
void cal(int reta[],int retb[],int basereal,int baseima,int rmd){
    int real[N]={0},ima[N]={0};
    cal1(real,reta,retb,basereal,baseima);//temp.real=a.real*basereal-a.ima*baseima;
    cal2(ima,reta,retb,basereal,baseima);//temp.ima=a.real*baseima+a.ima*basereal;
    for(int i=0;i<N;i++){
        reta[i]=real[i];retb[i]=ima[i];
    }
    int idx=1;
    while(reta[idx]==0&&idx<N)idx++;
    if(idx==N){reta[0]=0;reta[N-1]=rmd;return;}
    if(reta[0]==-1){
        reta[N-1]-=rmd;
        for(int i=N-1;i>0;i--){
            if(reta[i]<0){reta[i]+=10;reta[i-1]-=1;}
        }
    }
    else{
        reta[N-1]+=rmd;
        for(int i=N-1;i>0;i--){
            reta[i-1]+=reta[i]/10;
            reta[i]%=10;
        }
    }
}
int main(){
    char hex[500000];
    scanf("%s",hex);
    if(strcmp("0x0",hex)==0){printf("0");return 0;}
    int binary[N]={1000000};
    int idx=3;
    for(int i=2;i<strlen(hex);i++){
        int num=hex[i]>='A'?hex[i]-'A'+10:hex[i]-'0';
        int i=idx;
        for(int j=0;j<4;j++){
            binary[i--]=num%2;
            num/=2;
        }
        idx+=4;
    }
    idx-=4;
    int rmd;
    int reta[N]={0},retb[N]={0};
    reta[N-1]=binary[0];
    int basereal=-1,baseima=1;
    for(int j=1;j<=idx;j++){
        rmd=binary[j];
        cal(reta,retb,basereal,baseima,rmd);
    }
    int flag=0;
        for(int i=N-1;i>0;i--){
            if(reta[i]!=0){flag=1;break;}
        }
        if(flag)if(reta[0]==-1)putchar('-');
        for(int i=1;i<N;i++){
            if(reta[i]!=0){
                while(i<N)printf("%d",reta[i++]);}
        }
        if(flag){
            for(int i=N-1;i>0;i--)if(retb[i]!=0){flag=0;break;}
            if(flag==0)
                if(retb[0]==0)putchar('+');
        }
        int flag1=0;
        for(int i=N-1;i>0;i--){
            if(retb[i]!=0){flag1=1;break;}
        }
        if(flag1==0)return 0;
        if(retb[0]==-1)putchar('-');
        idx=1;
        while(retb[idx]==0&&idx<N)idx++;
        if(idx==N-1&&retb[idx]==1){
            putchar('i');return 0;
        }
        for(;idx<N;idx++){
            flag1=1;
            printf("%d",retb[idx]);
        }
        putchar('i');
}