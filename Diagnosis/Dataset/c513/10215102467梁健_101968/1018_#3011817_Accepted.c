#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int s[26],k=0;
    char c;
    do{
        scanf("%d",&s[k++]);
    }while(c=getchar()==',');
    int num[26],t=1;
    num[0]=2;
    for(int i=3;t<26;i+=2){
            int flag=0;
        for(int j=1;j<sqrt(i)+1;j++){
            if(i%j==0)flag++;
        }
        if(flag<2)num[t++]=i;
    }
    int n[26][60];
    for(int i=0;i<26;i++){
        for(int j=0;j<60;j++){
            n[i][j]=0;
        }
    }
    n[0][0]=1;
    int tp=0;
    for(int i=1;i<26;i++){
        for(int j=0;j<=tp;j++){
            n[i][j]=n[i-1][j]*num[i-1];
        }
        for(int j=0;j<=tp;j++){
            if(n[i][j]>=10){
                n[i][j+1]+=(n[i][j]/10);
                n[i][j]%=10;
                tp=tp>j+1?tp:j+1;
            }
        }
    }
    int res[100];
    for(int i=0;i<100;i++)res[i]=0;
    for(int i=k-1;i>=0;i--){
        for(int j=0;j<=tp;j++){
            res[j]+=s[i]*n[k-1-i][j];
        }
    }
    int rp=0;
    for(int i=0;i<99;i++){
        if(res[i]>0)rp=rp>i?rp:i;
        if(res[i]>=10){
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }
    }
    for(int i=rp;i>=0;i--)printf("%d",res[i]);
}

