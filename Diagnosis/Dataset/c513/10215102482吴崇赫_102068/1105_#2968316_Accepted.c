#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105

char* cutString(char* s,int begin,int end)
{
    char* ret=(char*)malloc(9);
    for(int i=0;i<9;++i)ret[i]=0;
    for(int i=begin,j=0;i<end;++i,++j)ret[j]=s[i];
    return ret;
}

int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

int minLBP(char* s)
{
    char temp[18];
    for(int i=0;i<18;++i)temp[i]=0;
    strcpy(temp,s);strcat(temp,s);
    char bit[8][9];
    for(int i=0;i<8;++i){
        strcpy(bit[i],cutString(temp,i,i+8));
        bit[i][8]=0;
    }
    qsort(bit,8,sizeof(bit[0]),cmp);
    int n=0;
    for(int i=0;i<8;++i){
        n=n*2+bit[0][i]-'0';
    }
    return n;
}

int main()
{
    int wide,height;
    scanf("%d %d\n",&wide,&height);
    int pic[N][N];
    for(int i=0;i<height;++i){
        for(int j=0;j<wide;++j)scanf("%d",&pic[i][j]);
    }

    for(int i=1;i<height-1;++i){
        for(int j=1;j<wide-1;++j){
            char t[9]={0};int p=0;
            t[p++]=pic[i][j]>pic[i-1][j-1]?'0':'1';
            t[p++]=pic[i][j]>pic[i-1][j]?'0':'1';
            t[p++]=pic[i][j]>pic[i-1][j+1]?'0':'1';
            t[p++]=pic[i][j]>pic[i][j+1]?'0':'1';
            t[p++]=pic[i][j]>pic[i+1][j+1]?'0':'1';
            t[p++]=pic[i][j]>pic[i+1][j]?'0':'1';
            t[p++]=pic[i][j]>pic[i+1][j-1]?'0':'1';
            t[p++]=pic[i][j]>pic[i][j-1]?'0':'1';
            t[p]=0;
            printf("%d ",minLBP(t));
        }
        printf("\n");
    }
    return 0;
}
