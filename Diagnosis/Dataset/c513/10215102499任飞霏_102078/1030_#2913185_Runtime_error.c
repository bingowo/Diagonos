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
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    char *x = *((char**)a);
    char *y = *((char**)b);
    int i = 0,j = 0;
    while(x[i]=='-')i++;
    while(y[j]=='-')j++;
    if(x[i] != y[j]){
        return (int)(y[j]-x[i]);
    }
    else{
        return atoi(x)-atoi(y);
    }
}
