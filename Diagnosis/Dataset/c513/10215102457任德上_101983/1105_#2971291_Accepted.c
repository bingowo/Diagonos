#include<stdio.h>
void cal(int *end,int *a,int p,int q,int w){
    int c[16]={0},min=256,now=0,t[8],m=8;
    t[0]=a[(p-1)*100+q-1];
    t[1]=a[(p-1)*100+q];
    t[2]=a[(p-1)*100+q+1];
    t[3]=a[p*100+q+1];
    t[4]=a[(p+1)*100+q+1];
    t[5]=a[(p+1)*100+q];
    t[6]=a[(p+1)*100+q-1];
    t[7]=a[p*100+q-1];
    for(int i=0;i<8;i++){
        if(t[i]>=a[p*100+q])c[i]=1;
        else c[i]=0;
    }
    for(;m<16;m++){
        for(int i=m-8;i<m;i++)now=now*2+c[i];
        if(now<min)min=now;
        now=0;
        c[m]=c[m-8];
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