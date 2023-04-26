#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
typedef struct {int win,lose,score,name;}team;
int cmp(const void*a,const void*b)
{
    team ta=*(team*)a,tb=*(team*)b;
    if(ta.score!=tb.score)return ta.score>tb.score?-1:1;
    if(ta.win!=tb.win)return ta.win>tb.win?-1:1;
    if(ta.lose!=tb.lose)return ta.lose>tb.lose?1:-1;
    return ta.name>tb.name?1:-1;
}
int main() {
    while(1)
    {
        int n,m,i,j;
        team a[10];
        memset(a,0,10*sizeof(a[0]));
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        for(i=0;i<n;i++)a[i].name=i+1;
        for(i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);x--;y--;
            if(z==1){a[x].win++;a[x].score+=3;a[y].lose++;a[y].score--;}
            if(z==0){a[x].score++;a[y].score++;}
            if(z==-1){a[y].win++;a[y].score+=3;a[x].lose++;a[x].score--;}
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(i=0;i<n;i++)printf("%d%c",a[i].name,i==n-1?'\n':' ');
    }
    return 0;
}
