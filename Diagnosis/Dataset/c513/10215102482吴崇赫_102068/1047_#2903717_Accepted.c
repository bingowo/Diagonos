#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 505

typedef struct
{
    int n;
    char c;
}word;

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
    word w[N];
    for(int i=0;i<N;++i){
        w[i].c='\0';
        w[i].n=1;
    }
    char input[N]={'\0'};
    scanf("%s",input);
    int p=0;
    w[p].c=input[0];
    for(int i=1;i<strlen(input);++i){
        if(input[i]==input[i-1]){
            w[p].n++;
            if(w[p].n>255){
                w[p].n=255;p++;
                w[p].c=w[p-1].c;
            }
        }
        else {
            p++;
            w[p].c=input[i];
        }
    }
    printf("case #%d:\n",x++);
    for(int k=0;k<p;++k){
        printf("%d%c",w[k].n,w[k].c);
    }
    printf("%d%c\n",w[p].n,w[p].c);}
    return 0;
}
