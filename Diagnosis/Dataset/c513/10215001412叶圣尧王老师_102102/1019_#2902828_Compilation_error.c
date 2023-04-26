#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct st
{
    int sign;
    int score;
    int vic;
    int los;
};

int main()
{
    int i,j,n,m,a,b,c;
    scanf("%d %d",&n,&m);
    while(n!=0&&m!=0)
    {
        struct st line[n]={
            .sign=0,
        .score=0,
        .vic=0,
        .los=0};
        for(i=0;i<m;i++)
        scanf("%d %d %d",&a,&b,&c);
        if(c>0){line[a].score+=3;line[b].score--;line[a].vic++;line[b].los--;}
    }
    
    
}