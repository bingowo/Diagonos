#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member
{
    char student_number[11];
    int mark;
}student[500];

int cmp(const void *a, const void *b);
long long my_atoi(char *a);

int main()
{
    int T,N,M,G;
    int a,b;
    int socore[11];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d %d",&N,&M,&G);
        for(int j=1;j<=M;j++)
            scanf("%d",&socore[j]);
        int num=0;
        for(int k=0;k<N;k++)
        {
            scanf("%s",student[k].student_number);
            scanf("%d",&a);
            int temp=0;
            for(int l=0;l<a;l++)
            {
                scanf("%d",&b);
                temp+=socore[b];
            }
            student[k].mark=temp;
            if(student[k].mark>=G)
                num++;
        }
        qsort(student,N,sizeof(student[0]),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",num);
        for(int m=0;m<num;m++)
            printf("%s %d\n",student[m].student_number,student[m].mark);
    }
    return 0;
}

int cmp(const void *a, const void *b)
{
    struct member *aa = (struct member*)a;
    struct member *bb = (struct member*)b;
    if(aa->mark != bb->mark)
        return bb->mark - aa->mark;
    else
    {
        if(my_atoi(aa->student_number)>my_atoi(bb->student_number))
            return 1;
        else
            return -1;
    }
}

long long my_atoi(char *a)
{
    int i=0;
    long long temp,sum=0;
    while(a[i]=='0')
        i++;
    for(;i<strlen(a);i++)
    {
        temp=a[i]-'0';
        sum=(sum+temp)*10;
    }
    sum=sum/10;
    return sum;
}