#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    unsigned long long a,b;
    scanf("%llu %llu",&a,&b);
    unsigned long long x=a,y=b;
    long long res;
    if(a==b){
        printf("1");
        return 0;
    }
    else res=2;
    int sa[50],sb[50];
    int k1=0,k2=0;
    while(x>0){//转化成9进制，倒置。
        sa[k1++]=x%9;
        x/=9;
        printf("%d",sa[k1-1]);
    }
    printf("\n");
    while(y>0){
        sb[k2++]=y%9;
        y/=9;
        printf("%d",sb[k2-1]);
    }
    printf("\n");
    for(int i=k1;i<k2;i++){
        sa[i]=0;
    }
    int time=0;
    for(int i=k2-1;i>0;i--){
        time=time*9+sb[i]-sa[i];
    }
    time--;
    printf("time=%d",time);
    return 0;
}

