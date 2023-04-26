#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct {
    char m;
    double times;
}strings;
int cmp(const void *p1,const void *p2){
    strings *a=(strings *)p1;
    strings *b=(strings *)p2;
    if(a->times != b->times){
        return b->times - a->times;
    }else if(islower(a->m)){
            return -1;
    }else{
        return 1;
    }
}
int main() {
    int T;
    for(int i=0;i<T;i++){
        int order[26];
        for(int j=0;j<26;j++){
            scanf("%lf",&order[j]);
        }
        strings a[101];
        int q=0;
        while ((a[q].m=getchar())&&(a[q].m!='\n')){
            if(islower(a[q].m)){
                a[q].times = order[a[q].m -'a'];
            }
            q++;
        }
        q= q-1;
        qsort(a,q, sizeof(strings),cmp);
        printf("case #%d:\n",i);
        for(int c=0;c<q;c++){
            printf("%c",a[c].m);
        }
        printf("\n");
    }

    return 0;
}
