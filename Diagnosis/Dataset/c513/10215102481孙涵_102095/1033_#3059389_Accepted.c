#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
int cmp(const void *a, const void *b);


struct data{
    int year;
    char monC[8];
    int monN;
    int day;
};

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        char *monthArr[18] = {"pop", "no","zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
        int N;
        scanf("%d",&N);
        struct data s[10001];
        for(int i = 0; i < N; i++){
            scanf("%d",&s[i].day);
            getchar();
            getchar();
            scanf("%s",s[i].monC);
            scanf("%d",&s[i].year);
            for(int j = 0; j < 18; j++){
                char *p1 = s[i].monC;
                char *p2 = monthArr[j];
                if(strcmp(p1,p2) == 0){
                    s[i].monN = j;
                }else if(strcmp(s[i].monC,"uayet") == 0){
                    s[i].monN = 18;
                }
            }
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf("case #%d:\n",t);
        for(int i = 0; i < N; i++){
            printf("%d. %s %d\n",s[i].day,s[i].monC,s[i].year);
        }

    }
    return 0;
}

int cmp(const void *a, const void *b){
    struct data d1;
    struct data d2;
    d1 = (*(struct data*)a);
    d2 = (*(struct data*)b);
    if(d1.year != d2.year){
        if(d1.year > d2.year){
            return 1;
        }else{
            return -1;
        }
    }else if(d1.monN != d2.monN){
        if(d1.monN > d2.monN){
            return 1;
        }else{
            return -1;
        }
    }else if(d1.day != d2.day){
        if(d1.day > d2.day){
            return 1;
        }else{
            return -1;
        }
    }
}
