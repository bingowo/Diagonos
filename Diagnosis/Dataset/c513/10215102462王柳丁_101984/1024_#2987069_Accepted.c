#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int score[11];
typedef struct student
{
    char num[12];
    int grade;
}STUDENT;
int cmp(const void *a,const void *b);
int main()
{
    int T,N,M,G,i;
    scanf("%d",&T);
    for(i=0;i<11;i++){score[i]=0;}
    for(i=0;i<T;i++)
    {
        scanf("%d %d %d",&N,&M,&G);
        int k,j,cnt1,cnt2=0,cnt=0,S;
        STUDENT a[501];
        for(k=1;k<=M;k++){scanf("%d",&score[k]);}
        char num1[12];
        for(k=0;k<N;k++)
        {
            scanf("%s",num1);
            scanf("%d",&S);
            for(j=0;j<S;j++)
            {
                scanf("%d",&cnt1);
                cnt2+=score[cnt1];
            }
            if(cnt2>=G)
            {
                a[cnt].grade=cnt2;
                strcpy(a[cnt].num,num1);
                cnt++;
            }
            cnt2=0;cnt1=0;
        }
        qsort(a,cnt,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
        for(k=0;k<cnt;k++)
        {
            printf("%s %d\n",a[k].num,a[k].grade);
        }
    }
    return 0;
}
int cmp(const void *a,const void *b)
{
    STUDENT *a1=(STUDENT *)a;
    STUDENT *b1=(STUDENT *)b;
    if(a1->grade!=b1->grade)return b1->grade-a1->grade;
    else return strcmp(a1->num,b1->num);
}
