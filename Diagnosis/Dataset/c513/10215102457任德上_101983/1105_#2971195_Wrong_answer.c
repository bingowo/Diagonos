#include<stdio.h>
void cal(int *end,int *a,int p,int q,int w){
    int c[16]={0},min=256,t=0,now=0;
    for(int i=p-1;i<=p+1;i++){
        for(int k=q-1;k<=q+1;k++){
            if(i==p&&k==q)continue;
            if(a[i*100+k]>=a[p*100+q])c[t++]=1;
            else c[t++]=0;
        }
    }
    for(;t<16;t++){
        for(int i=t-8;i<t;i++)now=now*2+c[i];
        if(now<min)min=now;
        now=0;
        c[t]=c[t-8];
    }
    *(end+(p-1)*98+(q-1))=min;
}
int main(){
    int w,h,a[100][100],end[1000];
    scanf("%d%d",&w,&h);
    for(int p=0;p<h;p++){
        for(int q=0;q<w;q++)scanf("%d",&a[p][q]);
    }
    for(int p=1;p<h-1;p++){
        for(int q=1;q<w-1;q++)cal(end,a[0],p,q,w);
    }
     for(int p=0;p<h-2;p++){
        for(int q=0;q<w-2;q++)printf("%d ",end[p*98+q]);
        printf("\n");
    }
    return 0;
}