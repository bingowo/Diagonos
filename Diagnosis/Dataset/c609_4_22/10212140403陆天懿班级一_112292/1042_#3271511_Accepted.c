#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
typedef long long ll;
typedef unsigned long long ull;
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

#define N 2005
#define M 75
char par[N],*line[M],*cur,*nxt;
int w,lc,ln,n,lw;

void PrintLine(){
    int blank=w-lw;
    for(int i=0;i<n;i++){
        if(i){
            for(int j=0;j<blank/(n-i);j++) printf(" ");
            blank-=blank/(n-i);
        }
        printf("%s",line[i]);
    }
    printf("\n");
}

int main(){
    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%d",&w);
        gets(par);
        gets(par);
        printf("case #%d:\n",cnt);
        cur=strtok(par," ");
        lc=strlen(cur);
        line[0]=cur;
        lw=lc;
        n=1;
        while(nxt=strtok(NULL," ")){
            ln=strlen(nxt);
            if(lw+n+ln<=w){
                line[n++]=nxt;
                lw+=ln;
            }
            else{
                PrintLine();
                lw=ln;
                line[0]=nxt;
                n=1;
            }
        }
        w=lw+n-1;
        PrintLine();
    }

    return 0;
}
