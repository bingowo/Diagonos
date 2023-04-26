#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,m;//球队数量，比赛场数
    scanf("%d%d",&n,&m);
    int a[10][100];//编号+计分
    for(int i=0;i<m;i++){
        int a,b;//球队编号
        int c;//标记
        scanf("%d%d%d",&a,&b,&c);
        if(c==0)l1++,l2++;
        else if(c==1)l1=l1+3,l2=l2-1;
        else l2=l2+3,l1=l1-1;
    }
    return 0;
}