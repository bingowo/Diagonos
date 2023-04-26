#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[14];//学号
    int k;
} N;
int fen[11];
int cmp(const void*a,const void*b)
{
    if(((N*)b)->k!=((N*)a)->k)return ((N*)b)->k-((N*)a)->k;
    return strcmp(((N*)a)->s,((N*)b)->s);
}
int main()
{
    N p[500];
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n,m,g,sum=0,t=0;
        scanf("%d %d %d",&n,&m,&g);
        for(int j=0;j<m;j++) scanf("%d",&fen[j]);//第一题到第m题，序号减一奥
        for(int j=0;j<n;j++){//循环内读入一个学生的信息
            sum=0;
            int x=0;
            int y;
            scanf("%s",p[t].s);
            scanf("%d",&x);
            for(int t=0;t<x;t++){
                scanf("%d",&y);
                sum += fen[y-1];
            }

            if(sum>=g){
                p[t].k=sum;
                t++;
            }
        }
        qsort(p,t,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",t);
        for(int j=0;j<t;j++){
            printf("%s %d\n",p[j].s,p[j].k);
        }
    }
	return 0;
}