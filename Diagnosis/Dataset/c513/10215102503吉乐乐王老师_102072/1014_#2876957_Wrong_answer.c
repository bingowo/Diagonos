#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;

int main(){
    lli a,b;
    scanf("%d %d",&a,&b);
    int normal[1000];
    int i=1;normal[0]=0;
    lli zheng=a/b;
    a%=b;
    do{
        normal[i++]=zheng%3;
        zheng/=3;
    }while(zheng);
    int p=1,q=i-1;
    while(p<q){
        char t=normal[p];normal[p]=normal[q];normal[q]=t;
        p++;q--;
    }
    normal[i]=(int)'.';
    while(a){
        normal[++i]=a*3/b;
        a=a*3%b;
    }
    for(int j=i;j>=1;j--){
        if(normal[j]==(int)'.')continue;
        normal[j]+=1;
        if(normal[j]>2){
            if(normal[j-1]==(int)'.'){normal[j-2]+=1;normal[j]-=3;}
            else{normal[j-1]+=1;normal[j]-=3;}
        }
    }
    for(int j=i;j>=1;j--){
        if(normal[j]==(int)'.')continue;
        normal[j]-=1;
        if(normal[j]==-1)normal[j]=2;
    }
    if(normal[0])printf("%d",normal[0]);
    for(int j=1;j<=i;j++){
        if((char)normal[j]=='.'){putchar('.');continue;}
        printf("%d",normal[j]);
    }
}
