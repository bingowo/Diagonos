#include <stdio.h>
#include <stdlib.h>

int cmp (const void*a,const void*b){
    int *p1,*p2;
    p1=*(int**)a;
    p2=*(int**)b;
    if (p1[0]==p2[0])
        if (p1[1]==p2[1])
            if (p1[2]==p2[2])
                return (p1[3]-p2[3]);
            else 
                return (p1[2]-p2[2]);
        else
            return (p2[1]-p1[1]);
    else
        return (p2[0]-p1[0]);
}

int main()
{
    int rule [6][3]={{-1,0,1},{3,1,0},{1,0,0},{1,0,0},{3,1,0},{-1,0,1}};
    int n,m;
    int **team;
    while (scanf("%d%d",&n,&m)&&(n!=0||m!=0)){
        team=(int **)malloc((n+1)*sizeof(int *));
        for (int i=0;i<n+1;i++){
        team[i]=(int *)malloc(4*sizeof(int));
        team[i][0]=0;
        team[i][1]=0;
        team[i][2]=0;
        team[i][3]=i;
        }
        for (int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            c++;
            for (int i=0; i<3;i++){
                team[a][i]+=rule[c*2][i];
                team [b][i]+=rule[c*2+1][i];
            }
        }
        qsort(team+1,n,sizeof(team[0]),cmp);
        for (int i=1;i<=n;i++)
        printf("%d%c",team[i][3],i==n?'\n':' ');
        for (int i=0;i<=n;i++)
            free(team[i]);
        free(team);
    }
    return 0;
}