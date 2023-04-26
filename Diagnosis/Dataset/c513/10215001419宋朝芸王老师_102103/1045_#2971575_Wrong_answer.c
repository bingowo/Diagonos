#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//all use subscript

typedef struct{
 char c;
 int cnt;
}PAIR;

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int sameLength(int *fn, PAIR **ra, int n){
    for(int i = 0; i < n; i++){
        if(fn[i] != fn[0]) return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < fn[0]; j++)
            if(ra[i][j].c != ra[0][j].c) return 0;
    }
    return 1;
}


int stat(char *a, PAIR *ra){
    char *p = a;
    char temp = *a; // for every location
    int cnt = 1;    //for every location
    int rcnt = 0;
    ra[0].c = temp;

    while(*p){
        if(*p != temp){
            ra[rcnt].cnt = cnt;
            cnt = 0;
            temp = *p;
            ra[++rcnt].c = temp;
        }
        else cnt++;
        p++;
    }
    ra[rcnt].cnt = cnt;

    return rcnt;
}

int main()
{
    static int n;
    scanf("%d",&n);

    char **a = (char**)malloc(sizeof(char*)*n);
    PAIR **ra = (PAIR**)malloc(sizeof(PAIR*)*n);
    int *fn = (int*)malloc(sizeof(int)*100);

    for(int i = 0; i < n; i++){
        a[i] = (char*)malloc(sizeof(char)*100);
        ra[i] = (PAIR*)malloc(sizeof(PAIR)*100);
        scanf("%s",a[i]);
        fn[i] = stat(a[i],ra[i]);
    }


    if(sameLength(fn,ra,n)){
        int ans = 0;

        for(int i = 0; i < fn[0]; i++){
            for(int j = 0; j < n; j++)
                fn[j] = ra[j][i].cnt;

            qsort(fn,n,sizeof(fn[0]),cmp);
            for(int k = 0; k < n; k++){
                ans += abs(fn[k] - fn[n/2]);
            }
        }

        printf("%d",ans);

    }
    else printf("-1");


    free(ra);
    free(a);
    return 0;
}
