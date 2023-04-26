#include<stdio.h>
#define N 25

int main()
{
    int upa[N],upd[N],downa[N],downd[N];
    upa[0]=upd[0]=downa[0]=downd[0]=0;
    upa[1]=1;upd[1]=downa[1]=downd[1]=0;
    upa[2]=downa[2]=0;upd[2]=downd[2]=1;
    upa[3]=upd[3]=downd[3]=1;downa[3]=0;
    upa[4]=downa[4]=downd[4]=1;upd[4]=2;downa[5]=1;
    for(int i=5;i<N;++i)upa[i]=upa[i-1]+upa[i-2];
    for(int i=5;i<N;++i)upd[i]=upd[i-1]+upd[i-2];
    for(int i=5;i<N;++i)downd[i]=downd[i-1]+downd[i-2];
    for(int i=6;i<N;++i)downa[i]=downa[i-1]+downa[i-2];
    //for(int i=0;i<N;++i)printf("%d %d\n",upd[i],downd[i]);
    //printf("%d",upd[7]);
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int alla[N];int alld[N];
    for(int i=0;i<N;++i)alla[i]=alld[i]=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<=i;++j){
            alla[i]+=(upa[j]-downa[j]);
            alld[i]+=(upd[j]-downd[j]);
        }
    }
    //printf("%d",alld[6]);
    int d=(m-alla[n-1]*a)/alld[n-1];
    printf("%d",alla[x]*a+alld[x]*d);
    //printf("%d",d);
    return 0;
}
