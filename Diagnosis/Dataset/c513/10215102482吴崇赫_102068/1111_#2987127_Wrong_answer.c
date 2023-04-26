#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 26
#define M 42

int xishu(char s[])
{
    int p=0,ret=0,flag=1;
    if(s[0]=='-'){++p; flag=-1;}
    while(s[p]!='x'&&p<strlen(s)){
        ret=ret*10+s[p++]-'0';
    }
    if(!ret)ret++;
    return ret*flag;
}

int findc(char c,char s[])
{
    for(int i=0;i<strlen(s);++i){
        if(s[i]==c)return i;
    }
    return -1;
}

int calculate(char s[],int x)
{
    int ret=0;
    char d[5][8];
    for(int i=0;i<5;++i){
        for(int j=0;j<8;++j)d[i][j]=0;
    }
    int di=0,dj=0;
    for(int i=0;i<strlen(s);++i){
        if(s[i]=='+'){
            di++;dj=0;
            //d[di][dj++]='+';
        }
        else if(s[i]=='-'&&i){
            di++;dj=0;
            d[di][dj++]='-';
        }
        else d[di][dj++]=s[i];
    }
    for(int i=0;i<=di;++i){
        //printf("%s\n",d[i]);
        int temp=1;
        int xi=xishu(d[i]);
        int idx1=findc('^',d[i]);
        int idx2=findc('x',d[i]);
        int ci=0;
        if(idx1!=-1)ci=d[i][idx1+1]-'0';
        if(idx1==-1&&idx2!=-1)ci=1;
        for(int j=0;j<ci;++j)temp*=x;
        temp*=xi;
        //printf("%d %d %d\n",xi,ci,temp);
        ret+=temp;
    }
    return ret;

}

int main()
{
    char input[30]={0};
    int cnt=0;
    while(scanf("%s",input)!=EOF){
    //int x=-2;
    //printf("%d\n",calculate("x^3-2x^2+3x-6",x));
    char temp[30];
    for(int i=0;i<30;++i)temp[i]=0;
    for(int ti=0,i=5;i<strlen(input);++i,++ti)temp[ti]=input[i];
    //printf("%s\n",temp);
    if(cnt)printf("\n");
    char cs[M][M];
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j)cs[i][j]=0;
    }
    for(int i=0;i<41;++i){
        for(int j=0;j<41;++j){
            if(i==20&&j==20)cs[i][j]='+';
            else if(i==20)cs[i][j]='-';
            else if(j==20)cs[i][j]='|';
            else cs[i][j]='.';
        }
    }
    cs[0][20]='^';cs[20][40]='>';

    for(int val=-20;val<=20;++val){
        int y=calculate(temp,val);
        if(y>20||y<-20)continue;
        //printf("%d\n",y);
        cs[20-y][20+val]='*';
    }

    for(int i=0;i<M;++i){
        printf("%s\n",cs[i]);
    }
    cnt++;
    }
    return 0;
}
