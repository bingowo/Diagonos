#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 105
int yy[N],mm[N],dd[N],
    h[N],m[N],
    s[N],r[N];
char name[N][130],ts[10];
int n,mode;

void Init(){
    for(int i=0;i<n;i++)
        r[i]=i;
}

int Cmp(const int* pa, const int* pb){
    if(mode==1&&s[*pa]!=s[*pb])
        return s[*pa]-s[*pb];
    if(mode==2){
        if(yy[*pa]!=yy[*pb]) return yy[*pa]-yy[*pb];
        if(mm[*pa]!=mm[*pb]) return mm[*pa]-mm[*pb];
        if(dd[*pa]!=dd[*pb]) return dd[*pa]-dd[*pb];
        if(h[*pa]!=h[*pb]) return h[*pa]-h[*pb];
        if(m[*pa]!=m[*pb]) return m[*pa]-m[*pb];
    }
    return strcmp(name[*pa],name[*pb]);
}

int main(){
    int ln=0;
    for(scanf("%d",&n);n;scanf("%d",&n)){
        if(ln) printf("\n");
        else ln=1;
        Init();
        for(int i=0;i<n;i++)
            scanf("%d-%d-%02d %d:%d %d %s",
                  yy+i,mm+i,dd+i,h+i,m+i,s+i,name+i);
        scanf("%*s%s",ts);
        if(ts[1]=='N') mode=0;
        else if(ts[1]=='S') mode=1;
        else mode=2;

        qsort(r,n,sizeof(r[0]),Cmp);
        for(int i=0;i<n;i++)
            printf("%04d-%02d-%02d %02d:%02d%16d %s\n",
                   yy[r[i]],mm[r[i]],dd[r[i]],
                   h[r[i]],m[r[i]],s[r[i]],name[r[i]]);
    }

    return 0;
}
