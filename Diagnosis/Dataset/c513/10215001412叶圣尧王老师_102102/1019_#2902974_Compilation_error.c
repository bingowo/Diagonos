#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->score-d->score<0)return 1;
    else if(c->score==d->score&&c->vic<d->vic)return 1;
    else return -1;
}

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
        struct st line[n];
        for(i=0;i<n;i++){line[i].sign=i+1;line[i].score=0;line[i].vic=0;line[i].los=0;}
        for(i=0;i<m;i++)
        {   scanf("%d %d %d",&a,&b,&c);
            if(c>0){line[a].score+=3;line[b].score--;line[a].vic++;line[b].los++;}
            else if(c<0){line[b].score+=3;line[a].score--;line[b].vic++;line[a].los++;}
            else {line[a].score++;line[b].score++;}
        }
        qsort(line,n,sizeof(line[0]),cmp);
        for(i=0;i<n;i++)printf("%d ",line[i].sign);
    }
    
    
    
}