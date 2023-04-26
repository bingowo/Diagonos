#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp(const void *a, const void * b);
double alpha[58];


int main()
{
    int T, t;
    scanf("%d",&T);
    for(t = 0; t < T; t++){
        for(int i = 0; i < 26; i++){
            scanf("%f",&alpha[i]);
            alpha[i + 32] = alpha[i];
        }
        char s[101];
        scanf("%s",s);
        int length = strlen(s);
        qsort(s,length,sizeof(s[0]),cmp);
        printf("case #%d:\n",t);
        printf("%s\n",s);
    }
    return 0;
}


int cmp(const void *a, const void * b){
    char c1;
    char c2;
    c1 = *(char *)a;
    c2 = *(char *)b;
    if (alpha[c1 - 65] != alpha[c2 - 65]){
        return alpha[c1 - 65] - alpha[c2 - 65] > 0 ? -1 : 1;
    }else if(abs(c1 - c2) == 32){
        return c1 > c2? -1:1;
    }
}
