#include <stdio.h>
#include <string.h>
//Cnm=m!/((m-n)!*n!)
/*
0
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1
1 5 10 10 5 1 
......
map[i][j]表示在i元素中抽取j个元素
*/
int main(){
    int T,m,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&m,&n);
        long long int map[50][50];
        map[0][0]=0;
        map[1][0]=1;
        map[1][1]=1;
        for(int t=2;t<=m;t++){
            for(int k=1;k<t;k++){
                map[t][k]=map[t-1][k-1]+map[t-1][k];
            }
            map[t][t]=map[t][0]=1;
        }
        printf("case #%d:\n", i);
        printf("lld",map[m][n]);
    }
    
}