#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void* b){
    int **s1=(int**)a,**s2=(int**)b;
    int *w1=*(s1),*w2=*(s2),t1=w2[1]-w1[1],t2=w2[2]-w1[2],t3=w1[3]-w2[3],t4=w1[0]-w2[0];
    if(t1)return t1;
    if(t2)return t2;
    if(t3)return t3;
    if(t4)return t4;
}
void Sort(int **p, unsigned n)//排序
{
    qsort(p,n,sizeof(int*),cmp); 
}

int main(){
    int N,m,a,b,c,wa,wb,la,lb;
    scanf("%d %d",&N,&m);
    int** n[N][4];
    for(int i=0;i<N;i++)
        for(int j=0;j<4;j++)
            n[i][j]=0;
    while(m>0){
        scanf("%d %d %d",&a,&b,&c);
        a--;b--;
        if(c==1){n[a][1]+=3;n[a][2]++;n[b][1]--;n[b][3]++;}
        if(c==-1){n[b][1]+=3;n[b][2]++;n[a][1]--;n[a][3]++;}
        if(c==0){n[a][1]++;n[b][1]++;}
        Sort(n,N);
        for(int i=0;i<N;i++) printf("%lld%c",n[i][0],i!=N-1?' ':'\n');
    }
    
    
}