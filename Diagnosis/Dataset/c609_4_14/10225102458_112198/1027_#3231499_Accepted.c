#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{char a[15];int mark;}student;
int cmp(const void* a,const void *b)
{
    student aa=*(student*)a;
    student bb=*(student*)b;
    if(aa.mark==bb.mark)return strcmp(aa.a,bb.a);
    else return bb.mark-aa.mark;
}
int main()
{
    int n,a,b,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        student stu[a];
        int score[b];
        for(int i=0;i<b;i++)scanf("%d",score+i);
        for(int i=0;i<a;i++){
            int max=0,m,mm;
            scanf("%s",stu[i].a);
            scanf("%d",&m);
            for(int i=0;i<m;i++){
                scanf("%d",&mm);
                max+=score[mm-1];
            }
            stu[i].mark=max;
        }
        qsort(stu,a,sizeof(stu[0]),cmp);
        int cnt=0;
        while(stu[cnt].mark>=c)cnt++;
        printf("case #%d:\n%d\n",i,cnt);
        for(int i=0;i<cnt;i++){
            printf("%s %d\n",stu[i].a,stu[i].mark);
    }
    }
    return 0;
}
