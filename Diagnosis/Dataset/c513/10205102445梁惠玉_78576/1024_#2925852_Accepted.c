#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grade[11];

struct STU{
    int mark;
    long long int num;
    char id[12];
};



int cmp(const void* a,const void* b)
{
    struct STU* p1=(*(struct STU**)a);
    struct STU* p2=(*(struct STU**)b);
    if(p1->mark==p2->mark)
    {
        if(p1->num>p2->num)
        {
            return 1;

        }
        else{return -1;}
    }
    if(p1->mark<p2->mark)
    {
        return 1;
    }
    else{
        return -1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N,M,G;
        scanf("%d %d %d",&N,&M,&G);
        for(int j=0;j<M;j++)
        {
            scanf("%d",&grade[j]);
        }
        struct STU* student[N+1];
        int count=0;
        for(int j=0;j<N;j++)
        {
            student[j]=(struct STU*)malloc(sizeof(struct STU));
            int S;
            scanf("%s",&student[j]->id);
            scanf("%d",&S);
            int f=0;
            for(int k=0;k<S;k++)
            {
               int flag;
               scanf("%d",&flag);
               f+=grade[flag-1];
            }
            long long int number=0;
            for(int pp=0;pp<11;pp++)
            {
             number*=10;
             number+=student[j]->id[pp]-'0';
             }
            student[j]->num=number;
            student[j]->mark=f;
            if(f>=G)
            {
                count++;
            }
        }
        if(count>0)
        {
            qsort(student,N,sizeof(student[0]),cmp);
            printf("%d\n",count);
            for(int qq=0;qq<count;qq++)
            {
                printf("%s %d\n",student[qq]->id,student[qq]->mark);
            }
        }
        else{
            printf("%d\n",count);
        }

    }
}
