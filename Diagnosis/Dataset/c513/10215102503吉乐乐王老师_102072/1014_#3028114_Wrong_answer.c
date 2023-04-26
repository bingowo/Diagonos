#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;

int main(){
    lli a,b;
    scanf("%lld %lld",&a,&b);
    int step[1000]={0};
    int idx=1;
    int sign=1;
    if(a<0){
        sign=-1;a=-a;
    }
    lli num=a/b;a=a%b;
    do{
        step[idx++]=num%3;
        num/=3;
    }while(num);
    int l=1,r=idx-1;
    while(l<r){
        int t=step[l];step[l]=step[r];step[r]=t;
        l++;r--;
    }
    int pos=idx;
    while(a){
        a*=3;
        step[idx++]=a/b;
        a%=b;
    }
    for(int i=idx-1;i>0;i--){
        step[i]+=1;
        step[i-1]+=step[i]/3;
        step[i]%=3;
    }
    for(int i=1;i<idx;i++)step[i]-=1;
    for(int i=0;i<idx;i++){
        if(step[i]==-1)step[i]=2;
        if(sign==-1){
            if(step[i]==2)step[i]=1;
            else if(step[i]==1)step[i]=2;
        }
    }
    while(idx>0&&step[idx-1]==0)idx--;
    for(int i=0;i<idx;i++){
        if(step[i]!=0){
            if(i>=pos){
                printf("0.");
            }
            while(i<idx){
                if(i==pos)printf(".");
                printf("%d",step[i++]);
            }
        }
    }
}
