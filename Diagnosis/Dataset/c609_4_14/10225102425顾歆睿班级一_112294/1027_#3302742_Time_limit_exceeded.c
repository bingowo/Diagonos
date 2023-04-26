#include<stdio.h>
#include<stdlib.h>

struct student
{
    char num;
    int sco;
}stu;

int cmp(const void *a, const void *b)
{

}

int main()
{
    int T,N,M,G;
    scanf("%d",&T);
    int score[11],i=0;
    while(scanf("%d",&score[i++])!=EOF);//输入分值
    char s[12];
    while(i--){
        scanf("%s",stu.num);//学号
        int S,sum=0,temp[11];
        scanf("%d",&S);
        while(S--){
            int j=0;
            scanf("%d",&temp[j]);
            sum+=score[temp[j]-1];
            j++;
        }
        stu.sco=sum;
    }
}
