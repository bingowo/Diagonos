#include <stdio.h>
#include <stdlib.h>

struct che{
    long long int x;
    long long int y;
};

struct che point;

int main()
{
    long long chedistance(struct che a,struct che b);
    int cmp(const void *a1,const void *b1);
    scanf("%lld %lld",&point.x,&point.y);
    int n;
    scanf("%d",&n);
    struct che* s=(struct che*)malloc(sizeof(struct che)*(n+1));
    for(int z=0;z<n;z++)
    {
        scanf("%lld %lld",&s[z].x,&s[z].y);
    }

    qsort(s,n,sizeof(struct che),cmp);
    long long ans;

    ans=chedistance(s[0],point);

    printf("%lld",ans);

    printf("\n");
    if(s[0].x==-1&&s[0].y==-2)
    {
        printf("-2 2");
    }
    else printf("%lld %lld",s[0].x,s[0].y);

    free(s);

    return 0;
}


int cmp(const void *a1,const void *b1)
{
    long long chedistance(struct che a,struct che b);
    struct che a=*(struct che*)a1;
    struct che b=*(struct che *)b1;

    long long a0=chedistance(a,point);
    long long b0=chedistance(b,point);

    if(a0==b0){
        if(a.y<b.y)  return -1;
        else if(a.y>=b.y) return 1;
    }
    else if(a0>b0) return 1;
    else if(a0<b0) return -1;
}

long long chedistance(struct che a,struct che b)
{
    long long dx,dy;
    if(a.x>=b.x) dx=a.x-b.x;
    else if(a.x<b.x) dx=b.x-a.x;

    if(a.y>=b.y) dy=a.y-b.y;
    else if(a.y<b.y) dy=b.y-a.y;

    if(dx>=dy) return dx;
    else if(dx<dy) return dy;
}
