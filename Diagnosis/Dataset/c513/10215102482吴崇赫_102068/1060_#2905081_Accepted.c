#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 105

int Max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    char input[N]={0};
    scanf("%s",input);
    int max=0,n=strlen(input);
    char num[N][N];
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)num[i][j]='\0';
    }
    int pi=0,pj=0;
    for(int i=0;i<n;++i){
        if(isdigit(input[i]))num[pi][pj++]=input[i];
        else {pi++;pj=0;}
    }
    //if(num[pi][0]=='\0')pi--;
    for(int i=0;i<=pi;++i){
        int cnt=0;int pk=0;
        while(num[i][pk++]=='0');
        while(num[i][pk++])cnt++;
        max=Max(max,cnt);
    }
    printf("%d",max+1);
    return 0;
}
