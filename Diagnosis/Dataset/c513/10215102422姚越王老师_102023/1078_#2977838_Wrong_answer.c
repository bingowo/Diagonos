#include<stdio.h>
#define C 100
typedef struct{int origin_height,water,mole,deno;} pos;
int GCD(int a,int b){return a%b?GCD(b,a%b):b;}
int main()
{
    int n,s,p,i,j;scanf("%d %d %d",&n,&s,&p);
    pos a[C];for(i=1;i<=n;++i){scanf("%d",&a[i].origin_height);a[i].water=a[i].mole=0;a[i].deno=2;}
    a[0].origin_height=a[0].water=a[n+1].origin_height=a[n+1].water=100000000;
    while(s)
    {
        for(i=p+1;i<=n+1;++i)if(a[i].origin_height+a[i].water>a[i-1].origin_height+a[i-1].water)break;
        for(j=p-1;j>=0;--j)if(a[j].origin_height+a[j].water>a[j+1].origin_height+a[j+1].water)break;
        if(i==n+1&&a[i-1].origin_height+a[i-1].water==a[p].origin_height+a[p].water){a[j+1].water++;s--;}
        else if(!j&&a[j+1].origin_height+a[j+1].water==a[p].origin_height+a[p].water){a[i-1].water++;s--;}
        else
        {
            a[i-1].mole++;
            if(a[i-1].mole==2){a[i-1].water++;a[i-1].mole=0;}
            a[j+1].mole++;
            if(a[j+1].mole==2){a[j+1].water++;a[j+1].mole=0;}
            s--;
        }
    }
    for(i=1;i<=n;++i)
    {
        if(a[i].mole==1)
        {
            int start,end,tmpwater=0,tmpmole=0,tmpdeno=2,div;
            for(start=i-1;start>=0;--start)if(a[start].origin_height>a[i].origin_height+a[i].water)break;
            for(end=i+1;end<=n+1;++end)if(a[end].origin_height>a[i].origin_height+a[i].water)break;
            for(j=start+1;j<=end-1;++j)
            {
                if(!a[j].mole){a[j].water--;tmpwater++;}
                else {a[j].mole--;tmpmole++;}
            }
            tmpmole+=tmpwater*2;
            tmpdeno*=(end-start+1);
            div=GCD(tmpmole,tmpdeno);tmpmole/=div;tmpdeno/=div;
            for(j=start+1;j<=end-1;++j){a[j].mole=tmpmole;a[j].deno=tmpdeno;}
        }
    }
    for(i=1;i<=n;++i)
    {
        if(!a[i].mole)printf("%d ",a[i].origin_height+a[i].water);
        else printf("%d+%d/%d ",a[i].origin_height+a[i].water,a[i].mole,a[i].deno);
    }
    return 0;
}
