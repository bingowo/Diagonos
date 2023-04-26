#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[16];
    long long num;
}S;

long long toll(int *a, int k, int len) {
    long long ans = 0;
    for(int i=0; i<len; ++i){
        ans = ans * k + a[i];
    }
    return ans;
}

int cmp(const void* m, const void* n){
    S *a = (S*)m, *b = (S*)n;
    if(a->num > b->num) return 1;
    else if(a->num == b->num)
        return strcmp(a->s,b->s);
    return -1;
}

int main()
{
   int N;
    scanf("%d",&N);
    S s[10000];
    for(int i=0; i<N; ++i) {
        scanf("%s",s[i].s);
        int num[130];
        for(int h=0; h<130; ++h) num[h] = -1;
        int a[16] = {0}, k = 1;
        for(int j=0; s[i].s[j]; ++j) {
            if(num[s[i].s[j]] == -1) {
                num[s[i].s[j]] = a[j] = k;
                if(j == 0) --k;
                else if(k == 0) k = 2;
                else ++k;
            }else  a[j] = num[s[i].s[j]];
        }
        if(k < 2) k = 2;
        s[i].num = toll(a,k,strlen(s[i].s));
    }
     qsort(s,N,sizeof(S),cmp);
     for(int i=0; i<N; ++i){
        printf("%s\n",s[i].s);
     }
     return 0;
}
