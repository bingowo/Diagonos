#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    int *w1=(int*)a,*w2=(int*)b,t1=w2[3]-w1[3],t2=w2[1]-w1[1],t3=w1[2]-w2[2],t4=w1[0]-w2[0];
    if(t1)return t1;
    if(t2)return t2;
    if(t3)return t3;
    if(t4)return t4;
}
void Sort(int (*p)[4], int n)//排序
{
    qsort(p,n,sizeof(int)*4,cmp); 
}

int main(){
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    while(!(n==0&&m==0)){
        int p[n+1][4];
        for(int i=0;i<=n;i++){
            p[i][0]=i;p[i][1]=0;p[i][2]=0;p[i][3]=0;//依次为球队编号、胜场数、负场数、积分
        }
        int a,b,c;
        while(m--){
            scanf("%d %d %d",&a,&b,&c);
            if(c==1){
                p[a][1]++;p[b][2]++;
                p[a][3]+=3;p[b][3]--;
            }
            if(c==-1){
                p[b][1]++;p[a][2]++;
                p[b][3]+=3;p[a][3]--;
            }
            if(c==0){
                p[b][3]++;p[a][3]++;
            }
        }
        Sort(p,n);
        for(int i=0;i<=n;i++)
            if(p[i][0]!=0)printf("%d%c",p[i][0],i!=n?' ':'\n');
        scanf("%d %d",&n,&m);
    }
    return 0;
}