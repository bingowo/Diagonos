#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char string[100];
    int u;//不同字母的个数；
}S;

int count(char *s){
    int temp[256]={0};
    int cnt = 0;
    for(int i=0;i<strlen(s);i++){
        if(temp[s[i]]==0){
            temp[s[i]]=1;
            cnt++;
        }
    }
    return cnt;
}

int cmp(const void *a,const void *b){
    const S *x=a,*y=b;
    if(x->u == y->u) return strcmp(x->string,y->string);
    else return y->u - x->u;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        S s[200];
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++) {
            scanf("%s", s[i].string);
            s[i].u = count(s[i].string);
        }    
        qsort(s, n, sizeof(S), cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++){
            printf("%s\n",s[j].string);
        }
    }
    return 0;
}
