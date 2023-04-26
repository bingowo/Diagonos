#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st
{
    char name[12];
    int num;
    int score;
}

int cmp(const void*a,const void*b)
{
    if((*(struct st*)a).score==(*(struct st*)b).score)
    return strcmp((*(struct st*)a).name,(*(struct st*)b).name);
    else return (*(struct st*)b).score-(*(struct st*)a).score;
}

int main()
{
    int T,N,M,G,S,i,j,k,e,line;
    scanf("%d",&T);
    for(i=0;i<N;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d%d%d",&N,&M,&G);
        int b[M+1]={0};struct st s[M];
        for(j=1;j<=M;j++)scanf("%d",&b[j]);line=0;
        for(j=0;j<N;j++)
        {scanf("%s %d",s[j].name,s[j].num);
         s[j].score=0;
         for(k=0;k<s[j].num;k++){scanf("%d",&e);s[j].score+=b[e];}
         if(s[j].score>=G)line++;
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf("%d\n",line);
        for(j=0;j<N;j++)printf("%s %d\n",s[j].name,s[j].score);
    }
}