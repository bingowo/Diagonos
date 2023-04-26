#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long int lli;

int way[101];
int step[2]={1,-1};

void walk(int n,int p,int m){
    if(m==1){
        if(p==1)way[2]++;
        else if(p==n)way[n-1]++;
        else{
            way[p+1]++;
            way[p-1]++;
        }
    }else{
        if(p==1)walk(n,2,m-1);
        else if(p==n)walk(n,n-1,m-1);
        else{
            walk(n,p+1,m-1);
            walk(n,p-1,m-1);
        }
    }
}


int main(){
    int cas;
    scanf("%d",&cas);
    for(int t=0;t<cas;t++){
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        memset(way,0,sizeof(way));
        walk(n,p,m);
        printf("%d\n",way[t]);
    }
    return 0;
}
