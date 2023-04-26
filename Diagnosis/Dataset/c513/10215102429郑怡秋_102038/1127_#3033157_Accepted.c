#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int fenz;
    int fenm;
}FEN;
int gc(int x,int y)
{
    if(y==0) return x;
    return gc(y,x%y);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    FEN*p=(FEN*)malloc((n+1)*sizeof(FEN));
    int fm=1,fz=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d/%d",&p[i].fenz,&p[i].fenm);
        fm*=p[i].fenm;
    }
    for(int i=0;i<n;i++)
    {
        fz+=(fm/p[i].fenm)*p[i].fenz;
    }
    int ans=0;
    ans=gc(fm,fz);
    printf("%d/%d\n",fz/ans,fm/ans);
    return 0;
}
