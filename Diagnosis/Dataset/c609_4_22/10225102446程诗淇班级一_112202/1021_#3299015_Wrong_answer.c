#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[25];
    int t[25];
    int len;
} num1;
int cmp(const void *a,const void *b){
    int c;
    int d;
    int n=0;
    c=(*(num1*)a).t[n];
    d=(*(num1*)b).t[n];
    int x=(*(num1*)a).len;
    int y=(*(num1*)b).len;
    while(c==d&&n<x&&n<y){
        n++;
        c=(*(num1*)a).t[n];
        d=(*(num1*)b).t[n];
    }
    if(n<x&&n<y){
        return c-d;}
    else if(n<x){
        return c-d;
    }
    else{
        return d-c;
    }


}
int main()
{
    char table[26];
    while(scanf("%s",table)!=EOF){
        num1* hhh;
        hhh=(num1*)malloc(100*sizeof(hhh[0]));
        int i=0;
        int a;
        char g;
        while(scanf("%s",hhh[i].s)){
            a=0;
            int b;
            b=strlen(hhh[i].s);
            hhh[i].len=b;
            while(a!=b){
                for(int j=0;j<26;j++){
                    if((table[j]==hhh[i].s[a])||table[j]==((hhh[i].s[a])-32)){
                        hhh[i].t[a]=j;
                        break;
                    }
                }
                a++;
            }
            i++;
            g=getchar();
            if(g=='\n'){
                break;
            }

        }
        qsort(hhh,i,sizeof(num1),cmp);
        for(int k=0;k<i;k++){
            printf("%s ",hhh[k].s);
        }
        printf("\n");
        free(hhh);

    }
    return 0;


}
