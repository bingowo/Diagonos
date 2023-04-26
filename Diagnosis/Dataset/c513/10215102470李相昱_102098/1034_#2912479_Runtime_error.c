#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct {
    char m;
    double times;
    int d;
}strings;
int cmp(const void *p1,const void *p2){
    strings *a=(strings *)p1;
    strings *b=(strings *)p2;
    if(a->times != b->times){
        return b->times > a->times?1:-1;
    }else if(a->d == b->d){
        return islower(a->m)?-1:1;
    }else{
        return a->d - b->d;
    }
           
    
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        double order[26];
        for(int j=0;j<26;j++){
            scanf("%lf",&order[j]);
        }
        strings a[101];
        int q=0;
        while ((a[q].m=getchar())&&(a[q].m!='\n')){
            if(islower(a[q].m)){
                a[q].d = a[q].m -'a';
                a[q].times = order[a[q].d];
            }
            else{
                a[q].d = a[q].m -'A';
                a[q].times = order[a[q].d];
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
