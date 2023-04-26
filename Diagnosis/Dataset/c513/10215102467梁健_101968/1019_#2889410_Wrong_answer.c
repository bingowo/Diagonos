#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct team{
    int num;
    int sco;
}TEAM;
int comp1(const void *a,const void *b){
    int sa,sb;
    TEAM a1=*(TEAM *)a;
    TEAM b1=*(TEAM *)b;
    sa=a1.sco,sb=b1.sco;
    if(sa!=sb)return sb-sa;
    else return a1.num-b1.num;
}
int main()
{
    TEAM* a=NULL;
    int m,n;
    scanf("%d %d",&n,&m);
    do{
    a=(TEAM*)malloc(sizeof(TEAM)*n);
    for(int i=0;i<n;i++){
        a[i].num=1+i,a[i].sco=0;
    }
    for(int i=0;i<m;i++){
        int z,b,sit;
        scanf("%d %d %d",&z,&b,&sit);
        if (sit==1)a[z-1].sco+=3,a[b-1].sco-=1;
        if (sit==0)a[z-1].sco+=1,a[b-1].sco+=1;
        else a[z-1].sco-=1,a[b-1].sco+=3;
    }
    qsort(a,n,sizeof(TEAM),comp1);
    for(int step=0;step<n-1;step++){
        printf("%d ",a[step].num);
    }
    printf("%d\n",a[n-1].num);
    scanf("%d %d",&n,&m);
    }while(m!=0&&n!=0);
    return 0;
}
