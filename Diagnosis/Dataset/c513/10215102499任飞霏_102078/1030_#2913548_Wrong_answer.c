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
        qsort(s,N,sizeof(s[0]),cmp);
        for(int k = 0;k < N;k++){
            printf("%s ",s[k]);
        }
        printf("\n");
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    char *x = *(char(*)[20])a;
    char *y = *(char(*)[20])b;
    int i = 0,j = 0;
    if(x[i]=='-')i++;
    if(y[j]=='-')j++;
    if(x[i] == y[j]){
        char *p;
        return strtol(x,&p,10) - strtol(y,&p,10);
    }
    else{
        return y[j]-x[i];
    }
}
