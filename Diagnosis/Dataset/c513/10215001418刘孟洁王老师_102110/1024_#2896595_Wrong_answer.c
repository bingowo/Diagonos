#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{char number[12];int score;}information;

int compare(const void*a,const void*b)
{
    information c=*(information*)a;
    information d=*(information*)b;
    int i;
    if(c.score!=d.score)return d.score-c.score;
    else if(c.number>d.number)
    {
        long long int s1=0,s2=0;
        for(i=0;i<11;i++)
        {
            s1=s1*10+c.number[i]-'0';
            s2=s2*10+d.number[i]-'0';
            
        }
        if(s1<s2)return -1;
        else return 1;
        }
}

int main()
{
    int i,stu,ques,sco,x,k,l,c,n,num;
    int *s,*t;
    information *in,right[501];
    scanf("%d",&n);//问题数；
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&stu,&ques,&sco);//学生人数、题目数、分数线；
        s=(int*)malloc(sizeof(int)*ques);
        in=(information*)malloc(stu*sizeof(information));
        for(k=0;k<ques;k++)scanf("%d",&s[k]);//每道题的分数；
        for(k=0,l=0;k<stu;k++)//一个一个输入学生学号及对的题目；
        {
            scanf("%s%d",in[k].number,&num);
            t=(int*)malloc(num*sizeof(int));
            in[k].score=0;
            for(x=0;x<num;x++)scanf("%d",&t[x]);//输入对的题目
            for(x=0;x<num;x++)in[k].score=in[k].score+s[t[x]-1];
            if(in[k].score>=sco){right[l]=in[k];l++;}
        }
        qsort(right,l,sizeof(right[0]),compare);
        printf("case #%d:\n",i);
        printf("%d\n",l);
        for(c=0;c<l;c++)printf("%s %d\n",right[c].number,right[c].score);
    }
}
