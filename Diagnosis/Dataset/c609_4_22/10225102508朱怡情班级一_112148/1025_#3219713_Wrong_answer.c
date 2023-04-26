#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    if(((int*)a)[0]!=((int*)b)[0])
        return ((int*)b)[0]-((int*)a)[0];
    else if(((int*)b)[1]!=((int*)a)[1])return ((int*)b)[1]-((int*)a)[1];
    else return ((int*)a)[2]-((int*)b)[2];
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)){
        int team[11][3]={0};
        if(n==0&&m==0)break;
        int a,b,c;
        for(int i=1;i<=n;i++)team[i][2]=i;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                team[a][0]+=3;
                team[a][1]++;
                team[b][0]--;
            }
            else if(c==-1){
                team[a][0]--;
                team[b][0]+=3;
                team[b][1]++;
            }
            else{
                team[a][0]++;
                team[b][0]++;
            }
        }
        qsort(team+1,n,sizeof(team[1]),cmp);
        for(int i=1;i<=n;i++)printf("%d ",team[i][2]);
        printf("\n");
    }
    return 0;
}
