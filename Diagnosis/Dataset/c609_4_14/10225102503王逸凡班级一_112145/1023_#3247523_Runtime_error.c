#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
    int y;
    int d;
    char m[7];
}Maya;

int month2idx(char *m){
    static char* month[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax",
    "zac","ce","mac","kankin","muan","pax","koyab","cumhu","uayet"};

    for (int i = 0;;i++){
        if(!strcmp(m,month[i])){
            return i;
        }
    }
}

int cmp(const void* a,const void *b){
    return ((Maya*)a)->val-((Maya*)b)->val;
}

int main()
{
    int T;
    int N;
    Maya a[10001];
    scanf("%d",&T);
    for (int i = 0;i<T;i++){
        scanf("%d",&N);
        for (int j = 0;j<N;j++){
            scanf("%d. %s %d",&a[j].d,&a[j].m,&a[j].y);
            a[j].val = a[j].y*1000+month2idx(a[j].m)*20+a[j].d;
        }
        qsort(a,N,sizeof(Maya),cmp);
        printf("case #%d:\n",i);
        for (int k=0;k<N;k++){
            printf("%d. %s %d\n",a[k].d,a[k].m,a[k].y);
        }
    }
    return 0;
}
