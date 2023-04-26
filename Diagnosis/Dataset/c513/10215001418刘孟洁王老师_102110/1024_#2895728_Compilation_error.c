#include<stdio.h>
#include<stlib.h>
#include<string.h>

typedef struct{long long int number;int score;}information;

int main()
{
    int i,stu,ques,sco,s[11];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&stu,&ques,&sco);
        for(i=0;i<ques;i++)scanf("%d",s[i]);
        for(k=0;k<stu;k++)//一个一个输入学生学号及对的题目；
        {
            scanf("%lld%d",&information[k].number,&num);
            for(x=0;x<num;x++)scanf("%d",t[x]);//输入对的题目
        }
    }
}