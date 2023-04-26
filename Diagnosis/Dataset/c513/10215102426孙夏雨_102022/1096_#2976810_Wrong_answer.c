#include <stdlib.h>
#include <stdio.h>

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if((*p1)>*(p2)) return 1;
    else return 0;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        int* p1=(int* )malloc(n*sizeof(int));
        int* p2=(int* )malloc(n*sizeof(int));
        for(int i=0;i<n;i++) scanf("%d %d",p1+i,p2+i);
        qsort(p1,n,sizeof(int),cmp);
        int i1=0,i2=0;
        while(i1<n&&i2<n){
            if((*(p1+i1))==(*(p2+i2))) {printf("Poor dxw!\n");break;}
            else if((*(p1+i1))<(*(p2+i2)))i1++;
            else i2++;
        }
        if(i1==n||i2==n) printf("Lucky dxw!\n");
        free(p1);
        free(p2);
    }
    return 0;
}
