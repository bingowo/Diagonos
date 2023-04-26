#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[100];
    int k;//k表示数字
} N;
int cmp(const void*a,const void*b)
{
    if(((N*)a)->k==((N*)b)->k) return strcmp(((N*)a)->s,((N*)b)->s);
    else{
        return ((N*)a)->k-((N*)b)->k;
    }
}
int main()
{
    N p[100];
    int i=0,t=0;
    while(scanf("%s",&p[i].s)!=EOF){
        for(int j=0;j<strlen(p[i].s);j++){
            if(isdigit(p[i].s[j])) {
                t=j;
                break;
            }
        }
        if(t){
            p[i].k=atoi(p[i].s+t);
        }
        else p[i].k=0;
        i++;
    }
    qsort(p,i,sizeof(p[0]),cmp);
    for(int j=0;j<i;j++) printf("%s ",p[j].s);
    return 0;
}