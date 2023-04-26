#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int Comb(int n,int m,int**table)
{
    int s;
    if(*(*(table + n) + m) != -1)
        return *(*(table + n) + m) % 1007;
    if(n == m)
        s = 1;
    else if(m == 1)
        s = n % 1007;
    else if(m == 0)
        s = 0;
    else
        s =  (Comb(n - 1,m,table) % 1007 + Comb(n - 1,m - 1,table) % 1007) % 1007;
    *(*(table + n) + m) = s;
    return s;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int a,b,k,n,m;
        int**table;
        int ef;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        int table[k][k];
        memset(table,-1,sizeof(int) * k * k);
        //table = (int**)malloc(k*sizeof(int*));
        //for(int i = 0;i < k;i++)
        //{
        //    table[i] = (int*)malloc(sizeof(int) * k);
        //}
        //memset(table,-1,sizeof(int) * k * k);
        ef = (((int)pow(a,n) % 10007) * ((int)pow(b,m) % 10007)) % 10007;
        if(n < m)
            ef = (ef * Comb(k,n,table)) % 10007;
        else 
            ef = (ef * Comb(k,m,table)) % 10007;
        printf("case #%d:\n%d\n",i,ef);
        //for(int i = 0;i < k;i++)
        //{
        //    free(table[i]);
        //}
        //free(table);
        return 0;
    }
}