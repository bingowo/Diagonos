#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int y;
    int s;
}point;
void jisuan(int h)
{
    int m=0,n=0,k=1,j=0,l=0,q=0,i=0;
    scanf("%d %d",&m,&n);
    point p[1000];
    memset(p,0,sizeof(int)*2000);
    l=m*10;
    for(i=1;;i++)
    {   p[k].y=l;p[k].s=l/n;l=(l%n)*10;
        if(l==0){break;}
        for(j=1;j<k;j++){if(p[k].y==p[j].y){q=j;break;}}
        if(q!=0)break;
        k++;
    }
    printf("case #%d:\n",h);
    printf("0.");
    if(l==0){for(i=1;i<=k;i++){printf("%d",p[i].s);}printf("\n");}
    else
    {
    for(i=1;i<k;i++){printf("%d",p[i].s);}printf("\n");
    printf("%d""-""%d",q,k-1);printf("\n");
    }
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
