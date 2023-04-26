#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//n:共n号楼    p：耗子起始位置
//m：过了m分钟 t：耗子在t层
int solve(int n,int p,int m,int t)
{
    int minus=p-t;
    if((m+minus)%2==1)return 0;
    else{
        int on=(m+minus)/2,down=(m-minus)/2;
        return 1;
    }

}
int main()
{
    int cas;scanf("%d",&cas);
    for(int i=0;i<cas;i++){
        int n,p,m,t;scanf("%d %d %d %d",&n,&p,&m,&t);
        printf("%d\n",solve(n,p,m,t));
    }
}
