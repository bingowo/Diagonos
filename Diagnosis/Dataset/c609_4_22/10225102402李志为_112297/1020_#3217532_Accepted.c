#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[100];
    int k,v;//k表示数字
} N;
int cmp(const void*a,const void*b)
{
    if(((N*)a)->k==1&&((N*)b)->k==1) {
        if(((N*)a)->v-((N*)b)->v) return ((N*)a)->v-((N*)b)->v;
        else return strcmp(((N*)a)->s,((N*)b)->s);
    }
    else if(((N*)a)->k==((N*)b)->k) return strcmp(((N*)a)->s,((N*)b)->s);
    else{
        return ((N*)a)->k-((N*)b)->k;
    }
}
int main()
{
    N p[100];
    int i=0,t=0,r=0;
    while(scanf("%s",&p[i].s)!=EOF){
            t=0,r=0;
        for(int j=0;j<strlen(p[i].s);j++){
            if(isdigit(p[i].s[j])) {
                t=1;
                r=j;
                break;
            }
        }
        if(t){
            p[i].k=atoi(p[i].s+r);
            p[i].v=1;//区分字符串和0和1
            if(p[i].k<1){
                p[i].k=1;
                p[i].v=0;
            }
        }
        else p[i].k=0;
        i++;
    }
    qsort(p,i,sizeof(p[0]),cmp);
    for(int j=0;j<i;j++) printf("%s ",p[j].s);
    return 0;
}