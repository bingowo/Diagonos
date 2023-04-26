#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 165
#define M 85

int Max(int a,int b){return a>b?a:b;}

int Min(int a,int b){return a<b?a:b;}

int main()
{
    char input[N]={0};
    while(scanf("%s",input)!=EOF){
        char ret[N][M];
        for(int i=0;i<N;++i){
            for(int j=0;j<M-1;++j)ret[i][j]=' ';
            ret[i][M-1]=0;
        }
        int min,max,ri,rj;
        ri=min=max=N/2;
        rj=0;
        ret[ri][rj]=input[0];
        for(int i=1;i<strlen(input);++i){
            rj++;
            if(input[i]>input[i-1])ri--;
            if(input[i]<input[i-1])ri++;
            min=Min(min,ri);
            max=Max(max,ri);
            ret[ri][rj]=input[i];
        }
        for(int i=min;i<=max;++i){
            printf("%s\n",ret[i]);
        }
    }
    return 0;
}
