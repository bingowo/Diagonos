#include <stdio.h>
#include <stdlib.h>

char *month[19] ={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

struct Maya{
    int day;
    char month[7];
    int year;
}a[10000];

int cmp(const void *a,const void *b){
    struct Maya *a1 = (struct Maya*)a,*b1 = (struct Maya*)b;
    if(a1->year != b1->year)return a1->year - b1->year;
    else{
        int m1,m2,i = 0;
        while(strcmp(month[i],a1->month) != 0)i++;
        m1 = i;
        i = 0;
        while(strcmp(month[i],b1->month) != 0)i++;
        m2 = i;
        printf("***%d***%d*\n",m1,m2);
        if(m1 != m2)return m1 - m2;
        else{
            return a1->day - b1->day;
        }
    }
}

int main()
{
    int T,N;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&N);
        for(int j = 0;j < N;j++){
            scanf("%d. %s %d", &a[j].day, a[j].month, &a[j].year);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < N;j++){
            printf("%d. %s %d\n", a[j].day, a[j].month, a[j].year);
        }
    }
    return 0;
}
