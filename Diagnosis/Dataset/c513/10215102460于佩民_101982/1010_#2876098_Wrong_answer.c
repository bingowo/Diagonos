#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    char a[600];
    int c[600];
    int result[600];
    int i,len,mod,leng,shu,now=1,number=0,j,sheng;
    scanf("%s",a);
    len=strlen(a);
    leng=len;
    char b[11];
    for(i=9;i>=0;i--){
        b[i]=len&1;
        len=len>>1;
    }
    printf("0001");
    for(i=0;i<10;i++){
        printf("%d",b[i]);
    }
    for(i=0;i<leng;i++){
        c[i]=a[i]-48;
    }
    mod=leng%3;
    shu=leng/3;
    if(mod==0) sheng=0;
    else if(mod==1) sheng=4;
    else if(mod==2) sheng=7;
    if(shu==0){
        if(sheng==4){
            i=0;
            number=number+c[i]*1;
            for(j=sheng-1;j>=0;j--){
                result[j]=number&1;
                number=number>>1;
            }}
        else if(sheng==7){
            for(i=0;i<2;i++){
            number=number+c[i]*(int)pow(10,1-i);}
            for(j=sheng-1;j>=0;j--){
                result[j]=number&1;
                number=number>>1;
            }
        }
        for(i=0;i<sheng;i++) printf("%d",result[i]);}
    while(now<=shu){
        for(i=(now-1)*3;i<3*now;i++){
            number=number+c[i]*(int)pow(10,3*now-1-i);
        }
        for(j=now*10-1;j>=(now-1)*10;j--){
            result[j]=number&1;
            number=number>>1;
        }
        number=0;
        now++;
    }
    number=0;
    if(now==shu){
        if(sheng==0);
        if(sheng==4){
            i=3*now;
            number=number+c[i]*1;
            for(j=now*10+sheng-1;j>=now*10;j--){
                result[j]=number&1;
                number=number>>1;
            }}
        if(sheng==7){
            for(i=3*now;i<3*now+2;i++){
                number=number+c[i]*(int)pow(10,3*now+1-i);
            }
            for(j=now*10+sheng-1;j>=now*10;j--){
                result[j]=number&1;
                number=number>>1;
            }
        }
    for(i=0;i<shu*10+sheng;i++) printf("%d",result[i]);}
    return 0;
}