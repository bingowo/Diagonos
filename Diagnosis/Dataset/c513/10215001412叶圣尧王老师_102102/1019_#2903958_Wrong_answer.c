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

int cmp(const void*a,const void*b)
{
    struct st*c=(struct st*)a;
    struct st*d=(struct st*)b;
    if(c->score - d->score<0)return 1;
    else if(c->score==d->score&&c->vic<d->vic)return 1;
    else if(c->score==d->score&&c->vic==d->vic&&c->los>d->los)return 1;
    else if(c->score==d->score&&c->vic==d->vic&&c->los==d->los&&c->sign>d->sign)return 1;
    else return -1;
}



int main()
{
    int i,j,n,m,a,b,c;
    scanf("%d%d",&n,&m);
    
    while(n!=0||m!=0)
    {   if(m==0){printf("%d\n",n);}
        else{
        struct st line[n];
        for(i=0;i<n;i++){line[i].sign=i+1;line[i].score=0;line[i].vic=0;line[i].los=0;}
        for(i=0;i<m;i++)
        {   scanf("%d %d %d",&a,&b,&c);
            if(c>0){line[a-1].score+=3;line[b-1].score--;line[a-1].vic++;line[b-1].los++;}
            else if(c<0){line[b-1].score+=3;line[a-1].score--;line[b-1].vic++;line[a-1].los++;}
            else {line[a-1].score++;line[b-1].score++;}
        }
        qsort(line,n,sizeof(line[0]),cmp);
        for(i=0;i<n-1;i++)printf("%d ",line[i].sign);
        printf("%d\n",line[i].sign);}
        scanf("%d%d",&n,&m);
    }

}
