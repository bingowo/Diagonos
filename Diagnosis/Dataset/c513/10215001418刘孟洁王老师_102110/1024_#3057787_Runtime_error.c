#include<stdio.h>
#include<string.h>

typedef struct
{
    char num[12];int score;
}inf;

int cmp(const void*a,const void*b)
{
    int i;
    inf c=*(inf *)a;
    inf d=*(inf *)b;
    if(c.score<d.score) return 1;
    else if(c.score>d.score) return -1;
    else
    {
        long long int s1=0,s2=0;
        for(i=0;i<12;i++)
        {
            s1=s1*10+c.num[i]-'0';
            s2=s2*10+d.num[i]-'0';
        }
        if(s1>s2) return 1;
        else return -1;
    }
}


int main()
{
    int i,stu,que,sco,x,k,l,c,n,number;
    int *s,*t;
    inf *in;
    inf right[501];
    scanf("%d",&n);//问题数
    for(i=0;i<n;i++)
    {
        scanf("%d%d%%d",&stu,&que,&sco);//学生数，题目数，分数线
        in=(inf*)malloc(stu*sizeof(inf));
        for(k=0;k<que;k++)//输入每道题的分数
            scanf("%d",&s[k]);
        for(k=0,l=0;k<stu;k++)//输入学生学号，对题个数和对的题目
        {
            scanf("%s%d",in[k].num,&number);
            in[k].score=0;
            for(x=0;x<number;x++)
                scanf("%d",&t[x]);
            for(x=0;x<number;x++)
                in[k].score=in[k].score+s[t[x]-1];//注意-1
            if(in[k].score>=sco)
            {
                right[l]=in[k];
                l++;
            }
        }
        qsort(right,l,sizeof(right[0]),cmp);
        printf("case #%d\n",i);
        printf("%d\n",l);
        for(c=0;c<l;c++)
            printf("%s %d\n",right[c].num,right[c].score);
    }
    return 0;
}
