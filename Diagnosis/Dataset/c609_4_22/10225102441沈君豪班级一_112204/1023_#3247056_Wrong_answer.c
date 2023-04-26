#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int a;
    char s[10]; //月份名字
    int b;      //月份排序
    int c;      //年份

}maya;

int cmp(const void*a,const void*b)
{
    maya A=*(maya*)a;
    maya B=*(maya*)b;
    if(A.c!=B.c){
        return A.c-B.c;
    }else{
        if(A.b!=B.b){
            return A.b-B.b;
        }else{
            return A.a-B.b;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    char table[20][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        maya* m=(maya*)malloc(sizeof(maya)*N);
        for(int j=0;j<N;j++){
            scanf("%d.",&m[j].a);
            scanf("%s",m[j].s);
            for(int k=0;k<20;k++){
                if(strcmp(table[k],m[j].s)==0){
                    m[j].b=k;
                    break;
                }
            }
            scanf("%d",&m[j].c);
        }
        qsort(m,N,sizeof(maya),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++){
            printf("%d. %s %d\n",m[j].a,m[j].s,m[j].c);
        }
    }
    return 0;
}
