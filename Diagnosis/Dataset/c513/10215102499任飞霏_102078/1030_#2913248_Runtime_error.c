#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b);

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        char s[10000][20];
        for(int j = 0;j < N;j++){
            scanf("%s",s[j]);
        }
        for(int j = 0;j < N;j++){
            printf("%s\n",s[j]);
        }
        qsort(s,N,sizeof(s[0]),cmp);
        for(int k = 0;k < N;k++){
            printf("%s ",s[k]);
        }
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    char *x = *((char**)a);
    char *y = *((char**)b);
    char *m = *((char**)a);
    char *n = *((char**)b);
    printf("%s",x);
    int i = 0,j = 0;
    while(*x=='-')x++;
    while(*y=='-')y++;
    if(*x != *y){
        return (int)(*y-*x);
    }
    else{
        return atoi(m)-atoi(n);
    }
}

