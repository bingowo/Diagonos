#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static double d[27];

int geta(char a){
    if(a <= 'Z' && a >= 'A') return 2*(a - 'A') + 1;
    else return 2*(a - 'a');
}

int geti(char a){
    if(a <= 'Z' && a >= 'A') return (a - 'A');
    else return (a - 'a');
}

int cmp(const void *a, const void *b){
    char ca = *(char*)a, cb = *(char*)b;
    if(d[geti(cb)] > d[geti(ca)]) return 1;
    else if(d[geti(cb)] < d[geti(ca)]) return -1;
    else return (geta(ca) - geta(cb));
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        for(int i = 0; i < 26; i++){
            scanf("%lf",&d[i]);
        }

        char a[101];
        scanf("%s",a);

        qsort(a,strlen(a),sizeof(a[0]),cmp);

        printf("case #%d:\n%s\n",R,a);

    }

    return 0;
}
