#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grade[11];

struct STU{
    char id[12];
    int mark;
    long long num;
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
        struct STU* student[N];
        int count=0;
        for(int j=0;j<N;j++)
        {

            char temp[12];
            int S;
            scanf("%s",temp);
            scanf("%d",&S);
            int f=0;
            for(int k=0;k<S;k++)
            {
               int flag;
               scanf("%d",&flag);
               f+=grade[flag-1];
            }
            if(f>=G)
            {
                student[count]->num=0;
                int pp=0;
                long long number=0;
                for(;pp<11;pp++)
                {
                    number*=10;
                    number+=temp[pp]-'0';
                }
                student[count]->num=number;

                strcpy(student[count]->id,temp);
                student[count]->mark=f;
                //printf("%lld %d\n",student[count]->num,student[count]->mark);
                count++;


            }
        }
        if(count>0)
        {
            qsort(student,count,sizeof(student[0]),cmp);
            printf("%d\n",count);
            for(int qq=0;qq<count;qq++)
            {
                printf("%s %d\n",student[qq]->id,student[qq]->mark);
            }
        }

    }




}
