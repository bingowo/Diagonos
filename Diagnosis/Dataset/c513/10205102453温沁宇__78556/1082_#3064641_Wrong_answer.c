#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500

int main()
{
    int a[2*L+1]={0},b[2*L+1]={0},N;
    char s[L+1],h[L+1];
    scanf("%s",s);
    scanf("%s",h);
    scanf("%d",&N);
    int i=0,j,k;
    while(s[i]&&s[i]!='.') i++; //定位小数点
    for(j=i-1,k=L;j>=0;j--,k--){
        a[k]=s[j]-'0'; //整数部分
    }
    for(j=i+1,k=L+1;j<strlen(s);j++,k++){
        a[k]=s[j]-'0'; //小数部分
    }
    i=0;
    while(h[i]&&h[i]!='.') i++;
    for(j=i-1,k=L;j>=0;j--,k--){
        b[k]=h[j]-'0';
    }
    for(j=i+1,k=L+1;j<strlen(s);j++,k++){
        b[k]=h[j]-'0';
    }
    int m;
    for(m=2*L;m>L+N;m--){
        a[m]+=b[m];
        a[m-1]+=a[m]/10;
        a[m]%=10;
    }
    if(a[m+1]>=5) a[m]++;
    for(m=L+N;m>0;m--){
        a[m]+=b[m];
        a[m-1]+=a[m]/10;
        a[m]%=10;
    }
    int p=0;
    while(p<=L&&a[p]==0) p++; //跳过前置0
    if(p>L) printf("0"); //整数部分为0
    else{
        for(;p<=L;p++){
            printf("%d",a[p]);
        }
    }
    printf(".");
    for(;p<=L+N;p++){
        printf("%d",a[p]);
    }
    return 0;
}
