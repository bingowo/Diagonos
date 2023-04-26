#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char code[12];
    int score;
}student;

int cmp(const void*a,const void*b)
{
    student aa=*((student*)a);
    student bb=*((student*)b);
    if(aa.score>bb.score) return -1;
    else if(aa.score<bb.score) return 1;
    else return strcmp(aa.code,bb.code);
}

int main()
{
    int T,i;
    scanf("%d",&T);
    //printf("T=%d",T);
    for(i=0;i<T;i++)
    {

        int n,m,g,j,s,k,co=0;
        int a[15];
        int tihao[10];
        student stu[1000];
        memset(a,0,15*sizeof(int));
        memset(tihao,0,10*sizeof(int));
        memset(stu,0,1000*sizeof(student));
        scanf("%d%d%d",&n,&m,&g);
        //printf("test:m=%d\n",m);
        /*for(j=0;j<n;j++)
        {
            printf("test:\n%s %d\n",stu[j].code,stu[j].score);
        }*/
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[j]);
        }
        /*for(j=0;j<m;j++)
        {
            printf("test:fenzhi of question[%d]%d\n",j+1,a[j]);
        }*/
        for(j=0;j<n;j++)
        {
            scanf("%s%d",stu[j].code,&s);
            for(k=0;k<s;k++)
            {
                scanf("%d",&tihao[k]);

            }
            for(k=0;k<s;k++)
            {
                stu[j].score+=a[tihao[k]-1];
            }
            //printf("test:score of stu[%d] is %d\n",j,stu[j].score);

        }
        for(j=0;j<n;j++)
        {
            if(stu[j].score>=g) co++;
        }
        qsort(stu,n,sizeof(student),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",co);
        for(j=0;j<co;j++)
        {
            printf("%s %d\n",stu[j].code,stu[j].score);
        }
    }
    return 0;

}
