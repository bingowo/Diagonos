#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int day;
    char *month;
    int year;
}DATE;
const char *Month = "pop0no0zip0zotz0tzec0xul0yoxkin0mol0chen0yax0zac0ceh0mac0kankin0muan0pax0koyab0cumhu0uayet";
int cmp1(const void *a, const void *b){
    DATE x1=*(DATE*)a, x2=*(DATE*)b;
    if(x1.year!=x2.year) return x1.year-x2.year;
    else if(x1.month!=x2.month) return strstr(Month, x1.month)-strstr(Month, x2.month);
    else return x1.day-x2.day;
}
int main(){
    int T, N, sum, flag, count;//flag标记当前读的是日还是年
    char c;
    scanf("%d", &T);
    DATE *dates;
    for(int k=0; k<T; k++){
        scanf("%d", &N);
        dates = (DATE*)malloc(sizeof(DATE)*N);
        getchar();
        for(int i=0; i<N; i++){
            dates[i].day = 0;
            dates[i].year = 0;
            dates[i].month = (char*)malloc(sizeof(char)*8);
            flag = 1;
            count = 0;
            scanf("%c", &c);
            while(c!='\n'){
                if(c>=48&&c<=57&&flag==1) dates[i].day = dates[i].day*10+(int)c-48;
                if(c=='.') flag++;
                if(c>='a'&&c<='z') dates[i].month[count++] = c;
                if(c>=48&&c<=57&&flag==2) dates[i].year = dates[i].year*10+(int)c-48;
                scanf("%c", &c);
            }
            dates[i].month[count] = '\0';
        }
        qsort(dates,N,sizeof(dates[0]),cmp1);
        printf("case #%d:\n", k);
        for(int i=0; i<N; i++)
            printf("%d. %s %d\n", dates[i].day, dates[i].month, dates[i].year);
        for(int i=0; i<N; i++) free(dates[i].month);
        free(dates);
    }
    return 0;
}