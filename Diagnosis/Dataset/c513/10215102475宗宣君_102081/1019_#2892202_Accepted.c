#include <stdio.h>
#include <stdlib.h>
typedef struct{
int x;
int y;
int w;
int f;
}ans;
int cmp(const void*a,const void *b)
{
    ans m,n;
    m = *(ans*)a;n = *(ans*)b;
    if(m.y>n.y) return -1;
    else if(m.y==n.y&&m.w>n.w) return -1;
    else if(m.y==n.y&&m.w==n.w&&m.f<n.f) return -1;
    else if(m.y==n.y&&m.w==n.w&&m.f==n.f&&m.x<n.x) return -1;
    else return 1;
}
int main()
{
    int n,m,a,b,c,i;
    while(1)
    {scanf("%d %d",&n,&m);
    if(n==0) return 0;
    ans d[n];
    for(i = 0;i<n;i++)
    {d[i].y = 0;d[i].w = 0;d[i].f = 0;d[i].x = i+1;}
    for(i = 0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(c==1) {d[a-1].y+=3;d[a-1].w+=1;d[b-1].y-=1;d[b-1].f+=1;}
        else if(c==0) {d[a-1].y += 1;d[b-1].y += 1;}
        else {d[a-1].y-=1;d[a-1].f+=1;d[b-1].y+=3;d[b-1].w+=1;}
    }
    qsort(d,n,sizeof(ans),cmp);
    for(i = 0;i<n;i++)
        printf("%d ",d[i].x);
    printf("\n");
    }
    return 0;
}
