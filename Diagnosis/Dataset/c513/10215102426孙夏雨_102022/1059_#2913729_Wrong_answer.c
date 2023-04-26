#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if((*(p1))>*((p2))) return 1;
    else return -1;
}

int f(int x,int y)
{
    int zuigy=1,z=1;
    int min=x<y?x:y;
    while(z<(min/2)){
        if((x%z==0)&&(y%z==0)&&(zuigy<z)) zuigy=z;
        z++;
    }
    return zuigy;
}

int main()
{
    int n=0,s=0;
    scanf("%d %d",&n,&s);
    int* p=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",p+i);
    qsort(p,n,sizeof(int),cmp);
    int zheng=*p,zi=0,mu=0,zuiai=*p,geshu=1,dishu=1,gdcha=0;
    while(s>0){
        while(*(p+geshu)==zuiai){
            if (geshu==n-1) break;
            dishu++;
            geshu++;
        }
        gdcha=*(p+geshu)-zuiai;
        if((s-dishu*gdcha>=0)&&(gdcha>0)){
            zuiai=*(p+geshu);
            s-=dishu*gdcha;
            zheng+=gdcha;
        }
        else if(gdcha>0){
            mu=dishu;
            while(s-dishu>=0){
                s-=dishu;
                zheng++;
            }
            zi=s;
            s-=dishu;
        }
        else{
            dishu=n;
            mu=n;
            while(s-dishu>=0){
                s-=dishu;
                zheng++;
            }
            zi=s;
            s-=dishu;
        }
    }
    if(zi==0) printf("%d",zheng);
    if(zi>0) {
        int w=f(zi,mu);
        zi/=w;
        mu/=w;
        if(mu==1) printf("%d",zheng+1);
        else if(zheng>0) printf("%d+%d/%d",zheng,zi,mu);
        else if(zheng==0) printf("%d/%d",zi,mu);
    }
    free(p);
    return 0;
}
