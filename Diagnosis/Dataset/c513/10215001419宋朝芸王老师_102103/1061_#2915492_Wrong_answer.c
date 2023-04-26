#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char a[16];
    long long int n;
}STR;


long long convert(char *a){
    int index[255];
    for(int i = 0; i < 255; i++) index[i] = -1;

    int digit = -1;
    long long res = 0;

    char *p = a;
    while(*p){
        if(index[*p] == -1){
            if(digit == -1){index[*p] = 1;digit++;}
            else if(digit == 0){index[*p] = 0; digit = 2;}
            else index[*p] = digit++;
        }
        p++;
    }

    p = a;
    if(digit == -1 || digit == 0) digit = 1;
    while(*p){
        res = res * digit + index[*p];
        p++;
    }

    return res;
}


int cmp(const void *a, const void *b){
    STR *pa = (STR*)a, *pb = (STR*)b;
    if(pa->n > pb->n) return 1;
    if(pa->n < pb->n) return -1;
    return strcmp(pa->a,pb->a);
}


int main()
{
    int N;
    scanf("%d",&N);

    STR *s=(STR*)malloc(N*sizeof(STR));

    for(int i = 0; i < N; i++){
        scanf("%s",s[i].a);
        s[i].n = convert(s[i].a);
    }

    qsort(s,N,sizeof(s[0]),cmp);

    for(int i = 0; i < N; i++){
        printf("%s\n",s[i].a);
    }
    
    free(s);

    return 0;
}
