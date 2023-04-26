#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct
{
    char num[12];
    int score;
}Infor;
int cmp(const void*a,const void*b)
{
    Infor*p1 = (Infor*)a;
    Infor*p2 = (Infor*)b;
    if(p1->score != p2->score)return p2->score-p1->score;
    else return strcmp(p1->num,p2->num);
}
int main()
{
    int n,stunum,quenum,line,i,j,k,passnum,scor,pass;
    scanf("%d",&n);

    for(i = 0;i<n;i++)
    {
        scanf("%d%d%d",&stunum,&quenum,&line);
        int* s = (int*)malloc(stunum*sizeof(int));
        for(j = 0;j<quenum;j++)
            scanf("%d",&s[j]);
        Infor* stu= (Infor*)malloc(stunum*sizeof(Infor));
        for(j = 0;j<stunum;j++)
        {
            stu[j].score = 0;
            scanf("%s",stu[j].num);
            scanf("%d",&passnum);
            for(k = 0;k<passnum;k++)
            {
                scanf("%d",&scor);
                stu[j].score+=s[scor-1];
            }
        }
        free(s);
        qsort(stu,stunum,sizeof(stu[0]),cmp);
        for(j = 0;stu[j].score>=line;j++);
        printf("case #%d:\n%d\n",i,j);
        for(k = 0;k<j;k++)
            printf("%s %d\n",stu[k].num,stu[k].score);
        free(stu);
    }
    return 0;
}