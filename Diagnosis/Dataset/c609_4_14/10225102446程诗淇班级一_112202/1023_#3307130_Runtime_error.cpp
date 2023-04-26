#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int day;
    int year;
    int a;
    char s[10];
}date;
int cmp(const void *x,const void *y){
    int m1,m2;
    m1=(*(date*)x).year;
    m2=(*(date*)y).year;
    if(m1!=m2){
        if(m1<m2){
            return -1;
        }
        else{
            return 1;
        }
    }
    else{
        int n1,n2;
        n1=(*(date*)x).day;
        n2=(*(date*)y).day;
        if(n1<n2){
            return -1;
        }
        else{
            return 1;
        }

    }

}

int main()
{
    int T1;
    scanf("%d",&T1);
    char table[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;i<T1;i++){
        int T2;
        scanf("%d",&T2);
        char c;
        int d;
        date* hhh;
        hhh=(date*)malloc(T2*sizeof(date));
        for(int j=0;j<T2;j++){
            scanf("%d",hhh[j].a);
            c=getchar();
            c=getchar();
            scanf("%s",hhh[j].s);
            int b;
            for(int k=0;k<19;k++){
                d=strcmp(table[k],hhh[j].s);
                if(d==0){
                    b=k;
                    break;
                }

            }
            hhh[j].day=hhh[j].a+20*b;
            scanf("%d",&hhh[j].year);
        }
        qsort(hhh,T2,sizeof(date),cmp);
        printf("case #%d:\n",i);
        for(int z=0;z<T2;z++){
            printf("%d. %s %d\n",hhh[z].a,hhh[z].s,hhh[z].year);
        }

    }
    return 0;
}
