#include<stdio.h>
#define C 1010
typedef struct{int origin_height,water,flag,mole,deno;} pos;
int GCD(int a,int b){return a%b?GCD(b,a%b):b;}
int main()
{
    int n,s,p,i,j,lastp1,lastp2;scanf("%d %d %d",&n,&s,&p);
    pos a[C];for(i=1;i<=n;++i){scanf("%d",&a[i].origin_height);a[i].water=a[i].flag=a[i].mole=0;a[i].deno=2;}
    a[0].origin_height=a[0].water=a[n+1].origin_height=a[n+1].water=100000000;
    while(s)
    {
        for(i=p+1;i<=n+1;++i)if(a[i].origin_height+a[i].water>a[i-1].origin_height+a[i-1].water)break;
        for(j=p-1;j>=0;--j)if(a[j].origin_height+a[j].water>a[j+1].origin_height+a[j+1].water)break;
        if(s==1){lastp1=i,lastp2=j;}
        if(i==n+1&&a[i-1].origin_height+a[i-1].water==a[p].origin_height+a[p].water){a[j+1].flag=1;a[j+1].water++;s--;}
        else if(!j&&a[j+1].origin_height+a[j+1].water==a[p].origin_height+a[p].water){a[i-1].flag=1;a[i-1].water++;s--;}
        else
        {
            a[i-1].mole++;a[i-1].flag=1;
            if(a[i-1].mole==2){a[i-1].water++;a[i-1].mole=0;}
            a[j+1].mole++;a[j+1].flag=1;
            if(a[j+1].mole==2){a[j+1].water++;a[j+1].mole=0;}
            s--;
        }
    }
    if(a[lastp1].origin_height+a[lastp1].water>a[lastp1+1].origin_height+a[lastp1+1].water||(a[lastp1].mole==1&&a[lastp1].flag==1))
    {
        int start,end,tmpwater=0,tmpmole=0,tmpdeno=2,div;
        for(start=lastp1-1;start>=0;--start)if(a[start].origin_height>a[lastp1].origin_height+a[lastp1].water)break;
        for(end=lastp1+1;end<=n+1;++end)if(a[end].origin_height>a[lastp1].origin_height+a[lastp1].water)break;
        for(j=start+1;j<=end-1;++j)
        {
            if(!a[j].mole){a[j].water--;tmpwater++;}
            else {a[j].mole--;tmpmole++;}
        }
        tmpmole+=tmpwater*2;
        tmpdeno*=(end-start-1);
        div=GCD(tmpmole,tmpdeno);tmpmole/=div;tmpdeno/=div;
        for(j=start+1;j<=end-1;++j){a[j].mole=tmpmole;a[j].deno=tmpdeno;a[j].flag=2;}
    }
    if(a[lastp2].origin_height+a[lastp2].water>a[lastp2-1].origin_height+a[lastp2-1].water||(a[lastp2].mole==1&&a[lastp2].flag==1))
    {
        int start,end,tmpwater=0,tmpmole=0,tmpdeno=2,div;
        for(start=lastp2-1;start>=0;--start)if(a[start].origin_height>a[lastp2].origin_height+a[lastp2].water)break;
        for(end=lastp2+1;end<=n+1;++end)if(a[end].origin_height>a[lastp2].origin_height+a[lastp2].water)break;
        for(j=start+1;j<=end-1;++j)
        {
            if(!a[j].mole){a[j].water--;tmpwater++;}
            else {a[j].mole--;tmpmole++;}
        }
        tmpmole+=tmpwater*2;
        tmpdeno*=(end-start-1);
        div=GCD(tmpmole,tmpdeno);tmpmole/=div;tmpdeno/=div;
        for(j=start+1;j<=end-1;++j){a[j].mole=tmpmole;a[j].deno=tmpdeno;}
    }
    for(i=1;i<=n;++i)
    {
        if(!a[i].mole)printf("%d ",a[i].origin_height+a[i].water);
        else printf("%d+%d/%d ",a[i].origin_height+a[i].water,a[i].mole,a[i].deno);
    }
    return 0;
}


