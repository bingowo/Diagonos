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
    int cnt = 0;    //for every location
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

    char ca[101];
    //PAIR ra[100000][100];
    PAIR **ra = (PAIR**)malloc(sizeof(PAIR*)*n);
    static int fn[100000];

    for(int i = 0; i < n; i++){
        scanf("%s",ca);
        ra[i] = (PAIR*)malloc(sizeof(PAIR)*100);
        fn[i] = stat(ca,ra[i]);
    }


    if(sameLength(fn,ra,n)){
        int ans = 0;
        int templen = fn[0];

        for(int i = 0; i <= templen; i++){
            for(int j = 0; j < n; j++)
                fn[j] = ra[j][i].cnt;

            qsort(fn,n,sizeof(fn[0]),cmp);
            for(int k = 0; k < n; k++)
                ans += abs(fn[k] - fn[n/2]);
        }

        printf("%d",ans);

    }
    else printf("-1");

    return 0;
}